/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:07:50 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 20:32:04 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long int n, t_printf_spec *spec, int print_len)
{
	int		digits;
	int		n_printed;
	char	*base_chars;

	n_printed = 0;
	base_chars = BASE_CHARACTERS;
	if (spec->conversion == 'X')
		base_chars = BASE_CHARACTERS_UP;
	if (spec->fl_hash && (spec->conversion == 'x') && n != 0)
		n_printed += write(1, "0x", 2);
	else if (spec->fl_hash && (spec->conversion == 'X') && n != 0)
		n_printed += write(1, "0X", 2);
	digits = count_digits_unsig_base(n, BASE_HEX);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_unbr_base(n, BASE_HEX, base_chars);
	return (n_printed);
}

int	ft_print_padded_hex(unsigned long long int n, t_printf_spec *spec, \
						int print_len)
{
	int	pad_size;
	int	n_printed;

	n_printed = 0;
	pad_size = 0;
	if (spec->fl_hash && n != 0)
		print_len += 2;
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if (spec->dot)
			n_printed += ft_print_pad(0, pad_size);
		else
			n_printed += ft_print_pad(spec->fl_zero, pad_size);
	}
	n_printed += ft_print_hex(n, spec, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	return (n_printed);
}

int	ft_process_hex(va_list args, t_printf_spec *spec)
{
	unsigned long long int	n;
	int						digits;
	int						print_len;

	n = ft_treat_uint_length_modifier(args, spec);
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = count_digits_unsig_base(n, BASE_HEX);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
		print_len = spec->precision;
	spec->tot_len += ft_print_padded_hex(n, spec, print_len);
	return (1);
}

int	ft_process_pointer(va_list args, t_printf_spec *spec)
{
	unsigned long	n;
	int				digits;
	int				print_len;

	n = (unsigned long int)va_arg(args, unsigned long int);
	if (!n)
	{
		spec->tot_len += ft_print_err(ERR_NULL_POINTER, spec);
		return (1);
	}
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = count_digits_unsig_base(n, BASE_HEX);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
		print_len = spec->precision;
	spec->fl_hash = 1;
	spec->conversion = 'x';
	spec->tot_len += ft_print_padded_hex(n, spec, print_len);
	return (1);
}
