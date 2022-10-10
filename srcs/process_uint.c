/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:40:57 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 20:13:19 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned long long int n, int print_len)
{
	int		digits;
	int		n_printed;

	n_printed = 0;
	digits = count_digits_unsig_base(n, BASE_DECIMAL);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_unbr_base(n, BASE_DECIMAL, BASE_CHARACTERS);
	return (n_printed);
}

/*
** special case for octate and hex when n > 0
** right align i.e. (symbol)||pad
** ft_print_uint_base: (symbol)||number
** pad
*/

int	ft_print_padded_uint(unsigned long long int n, \
								t_printf_spec *spec, int print_len)
{
	int	pad_size;
	int	n_printed;

	n_printed = 0;
	pad_size = 0;
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if (spec->dot)
			n_printed += ft_print_pad(0, pad_size);
		else
			n_printed += ft_print_pad(spec->fl_zero, pad_size);
	}
	n_printed += ft_print_uint(n, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(spec->fl_zero, pad_size);
	return (n_printed);
}

/*
** Process all unsigned integer input type include unsigned int, hex and octate
** determined by n_base value.
** when 0 is printed with an explicit precision 0, the output is empty.
** The precision, gives the minimum number of digits that must appear.
*/

int	ft_process_uint(va_list args, t_printf_spec *spec)
{
	unsigned long long int	n;
	int						digits;
	int						print_len;

	n = ft_treat_uint_length_modifier(args, spec);
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = count_digits_unsig_base(n, BASE_DECIMAL);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
		print_len = spec->precision;
	spec->tot_len += ft_print_padded_uint(n, spec, print_len);
	return (1);
}
