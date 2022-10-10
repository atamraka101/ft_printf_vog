/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:17:13 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 18:48:33 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_float_string(long double num, t_printf_spec *spec)
{
	char		*str;
	long double	tmp;

	str = NULL;
	tmp = num * ft_power_double(10, spec->precision);
	if (tmp - (long long)tmp == 0.5)
	{
		if (((long long)tmp % 2 != 1 && spec->len_modifier != LM_LD) \
			|| ((long long)tmp % 2 != 1 && \
					spec->len_modifier == LM_LD && spec->precision == 0))
			num = tmp / ft_power_double(10, spec->precision);
		else
			num = ft_round(num, spec->precision);
	}
	else
		num = ft_round(num, spec->precision);
	str = ft_ftoa(num, spec);
	return (str);
}

/*
** check_sign_float: one byte for sign if needed
** Get n converted to string
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
	if (print_len)
		n *= -1;
	str = process_float_string(n, spec);
	print_len += ft_strlen(str);
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	if (sign != '\0')
		n_printed += write(1, &sign, 1);
	n_printed += write(1, str, ft_strlen(str));
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	free(str);
	return (n_printed);
}

/*
** Precision determines how many digits after decimal point is printed
** when precision is not given, it is set to 6 by default
*/

int	ft_process_float(va_list args, t_printf_spec *spec)
{
	long double	n;

	n = ft_treat_float_length_modifier(args, spec);
	if ((n != n) || (n == -1.0 / 0.0) || (n == 1.0 / 0.0))
	{
		spec->tot_len += ft_process_float_err(n, spec);
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
