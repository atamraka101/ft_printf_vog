/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:49:52 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:09:00 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(long long int n, t_printf_spec *spec, int print_len)
{
	char	sign;
	int		digits;
	int		n_printed;

	n_printed = 0;
	check_sign(n, spec, &sign);
	if (sign != '\0')
		n_printed += write(1, &sign, 1);
	/*if (n < 0)
		n_printed += write(1, "-", 1);
	else
	{
		if (spec->fl_plus)
			n_printed += write(1, "+", 1);
		else if (spec->fl_space)
			n_printed += write(1, " ", 1);
	}*/
	digits = ft_count_digits(n);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_nbr(n);
	return (n_printed);
}

/*
** check for negative sign and explicit '+' sign
** pad || number
** sign||zero pad||number
** sign number||space
*/

int	ft_print_padded_int(long long int n, t_printf_spec *spec, int print_len)
{
	char	sign;
	int		fill_size;
	int		n_printed;

	n_printed = 0;
	print_len += check_sign(n, spec, &sign);
	/*if (sign != '\0')
		print_len ++;*/
	fill_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if ((sign != '\0') & spec->fl_zero)
		{
			n_printed += write(1, &sign, 1);
			spec->fl_plus = 0;
			spec->fl_space = 0;
			if (n < 0)
				n = n * (-1);
			print_len--;
		}
		n_printed += ft_print_pad(spec->fl_zero, fill_size);
	}
	n_printed += ft_print_int(n, spec, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(spec->fl_zero, fill_size);
	return (n_printed);
}

/*
** If precision is given, the 0 flag is ignored
** when 0 is printed with an explicit precision 0, the output is empty.
** The precision, gives the minimum number of digits that must appear.
*/

int	ft_process_int(va_list args, t_printf_spec *spec)
{
	long long int	n;
	int				digits;
	int				print_len;

	n = ft_treat_int_length_modifier(args, spec);
	//
	/*if (spec->dot)
		spec->fl_zero = 0;*/
	//
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = ft_count_digits(n);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
		print_len = spec->precision;
	spec->tot_len += ft_print_padded_int(n, spec, print_len);
	return (1);
}
