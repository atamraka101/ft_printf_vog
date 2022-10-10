/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:44:23 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 19:49:22 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_octal(unsigned long long int n, t_printf_spec *spec, int print_len)
{
	int	digits;
	int	n_printed;

	n_printed = 0;
	if (spec->fl_hash)
		n_printed += write(1, "0", 1);
	digits = count_digits_unsig_base(n, BASE_OCTATE);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_unbr_base(n, BASE_OCTATE, BASE_CHARACTERS);
	return (n_printed);
}

int	ft_print_padded_octal(unsigned long long int n, t_printf_spec *spec, \
							int print_len)
{
	int	pad_size;
	int	n_printed;

	n_printed = 0;
	pad_size = 0;
	if ((n == 0) && spec->fl_hash && !spec->dot)
		spec->fl_hash = 0;
	if (spec->fl_hash)
		print_len += 1;
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if (spec->dot)
			n_printed += ft_print_pad(0, pad_size);
		else
		n_printed += ft_print_pad(spec->fl_zero, pad_size);
	}
	n_printed += ft_print_octal(n, spec, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	return (n_printed);
}

int	ft_process_octal(va_list args, t_printf_spec *spec)
{
	unsigned long long int	n;
	int						digits;
	int						print_len;

	n = ft_treat_uint_length_modifier(args, spec);
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = count_digits_unsig_base(n, BASE_OCTATE);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
	{
		print_len = spec->precision;
		spec->fl_hash = 0;
	}
	spec->tot_len += ft_print_padded_octal(n, spec, print_len);
	return (1);
}
