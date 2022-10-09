/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:17:13 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:52 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa_int_digits(long double n)
{
	char		*str;
	long double	hold;
	int			i;
	int			str_count;

	i = 0;
	str_count = 0;
	hold = n;
	while (hold >= 10)
	{
		hold /= 10;
		str_count ++;
	}
	str = ft_strnew(str_count + 1);
	if (!str)
		return (NULL);
	while (str_count >= 0)
	{
		hold = n / ft_power_double(10, str_count);
		str[i++] = (long long)hold + '0';
		n -= ((long long)hold * ft_power_double(10.00, str_count));
		str_count--;
	}
	return (str);
}

/*
** converts the fraction digits (after decimal point) of a given float
** to a string
*/

char	*ft_ftoa_frac_digits(long double n, int precision)
{
	char		*str;
	long double	hold;
	int			i;
	int			count;

	i = 0;
	hold = n - (long int)n;
	count = precision + 1;
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	str[i++] = '.';
	while (i < count)
	{
		hold *= 10;
		str[i++] = (long long)hold + '0';
		hold -= (long long)hold;
	}
	return (str);
}

char	*ft_ftoa(long double n, t_printf_spec *spec)
{
	char	*str;
	char	*str_int;
	char	*str_frac;

	str_int = ft_ftoa_int_digits(n);
	if (spec->precision == 0)
	{
		if (spec->fl_hash)
			str_frac = ft_strdup(".");
		else
			str_frac = ft_strdup("");
	}
	else
		str_frac = ft_ftoa_frac_digits(n, spec->precision);
	str = ft_strjoin(str_int, str_frac);
	free(str_int);
	free(str_frac);
	return (str);
}

char	*process_float_string(long double num, t_printf_spec *spec)
{
	char		*str;
	long double	tmp;

	str = NULL;
	tmp = num * ft_power_double(10, spec->precision);
	if (tmp - (long long)tmp == 0.5)
	{
		if (((long long)tmp % 2 != 1 && spec->len_modifier != LM_LD)
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
	{
		n_printed += ft_print_pad(0, pad_size);
	}
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
