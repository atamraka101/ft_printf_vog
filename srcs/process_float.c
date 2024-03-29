/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:17:13 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 23:49:22 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints the given signed float along with
** sign if necessary
*/

int	ft_print_float(char *str, char sign)
{
	int	n_printed;

	n_printed = 0;
	if (sign != '\0')
		n_printed += write(1, &sign, 1);
	n_printed += write(1, str, ft_strlen(str));
	return (n_printed);
}

/*
** processes the given float number and converts it into a
** string.
*/

char	*process_float_string(long double n, t_printf_spec *spec)
{
	char		*str;
	long double	hold;

	str = NULL;
	hold = n * ft_power_double(10, spec->precision);
	if (hold - (long long)hold == 0.5)
	{
		if (((long long)hold % 2 != 1 && spec->len_modifier != LM_LD) \
			|| ((long long)hold % 2 != 1 && \
					spec->len_modifier == LM_LD && spec->precision == 0))
			n = hold / ft_power_double(10, spec->precision);
		else
			n = ft_round(n, spec->precision);
	}
	else
		n = ft_round(n, spec->precision);
	str = ft_ftoa(n, spec);
	return (str);
}

/*
** Process pad for the printing float.
** checks and stores the sign of the given number,
** converts it into positive number before processing.
** given number 'n' is converted to string
** calculate pad size
** pad || float
** Print sign first, if there is
*/

int	ft_print_padded_float(long double n, t_printf_spec *spec)
{
	int		n_printed;
	int		pad_size;
	int		print_len;
	char	sign;
	char	*str;

	n_printed = 0;
	print_len = check_sign_float(n, spec, &sign);
	if (sign == '-')
		n *= -1;
	str = process_float_string(n, spec);
	print_len += ft_strlen(str);
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if ((sign != '\0') && spec->fl_zero)
			n_printed += ft_print_sign_bf_pad(&sign, spec);
		n_printed += ft_print_pad(spec->fl_zero, pad_size);
	}
	n_printed += ft_print_float(str, sign);
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	free(str);
	return (n_printed);
}

/*
** Processes and prints float according to the given format.
** Error conditions:
** n != n ie. not a number it prints "nan" as error
** n = negative infinty (e.g. - x/0.0), prints "-inf"
** n = infinty (e.g. x/0.0), prints "inf"
** Considerations:
** - Precision determines how many digits after decimal point is printed
**   when precision is not given, it is set to 6 by default
*/

int	ft_process_float(va_list args, t_printf_spec *spec)
{
	long double	n;

	n = ft_treat_float_length_modifier(args, spec);
	if ((n != n) || (n == -1.0 / 0.0) || (n == 1.0 / 0.0))
	{
		spec->tot_len += ft_print_float_err(n, spec);
		return (1);
	}
	if (!spec->dot)
	{
		spec->dot = 1;
		spec->precision = 6;
	}
	spec->tot_len += ft_print_padded_float(n, spec);
	return (1);
}
