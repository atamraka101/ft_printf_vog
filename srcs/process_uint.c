/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:40:57 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:09:17 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint_base(unsigned long long int n, t_printf_spec *spec, \
						int print_len, int base_n)
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
	else if (spec->fl_hash && (spec->conversion == 'o') && n != 0)
		n_printed += write(1, "0", 1);
	digits = count_digits_unsig_base(n, base_n);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_unbr_base(n, base_n, base_chars);
	return (n_printed);
}

int	ft_print_prepend_symbol(t_printf_spec *spec)
{
	int	n_printed;

	n_printed = 0;
	if (!spec->fl_zero)
		return (0);
	if (spec->fl_hash && spec->conversion == 'x')
	{
		n_printed += write(1, "0x", 2);
		spec->fl_hash = 0;
	}
	else if (spec->fl_hash && spec->conversion == 'X')
	{
		n_printed += write(1, "0X", 2);
		spec->fl_hash = 0;
	}
	else if (spec->fl_hash && spec->conversion == 'o')
	{
		n_printed += write(1, "0", 1);
		spec->fl_hash = 0;
	}
	return (n_printed);
}

/*
** special case for octate and hex when n > 0
** right align i.e. (symbol)||pad
** ft_print_uint_base: (symbol)||number
** pad
*/

int	ft_print_padded_uint_base(unsigned long long int n, \
								t_printf_spec *spec, int print_len, int n_base)
{
	int	pad_size;
	int	n_printed;

	n_printed = 0;
	pad_size = 0;
	if (n_base == BASE_HEX && spec->fl_hash && n != 0)
		print_len += 2;
	else if (n_base == BASE_OCTATE && spec->fl_hash && n != 0)
		print_len += 1;
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if (n != 0)
			n_printed = ft_print_prepend_symbol(spec);
		print_len -= n_printed;
		n_printed += ft_print_pad(spec->fl_zero, pad_size);
	}
	n_printed += ft_print_uint_base(n, spec, print_len, n_base);
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

int	ft_process_uint(va_list args, t_printf_spec *spec, int n_base)
{
	unsigned long long int	n;
	int						digits;
	int						print_len;

	n = ft_treat_uint_length_modifier(args, spec);
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = count_digits_unsig_base(n, n_base);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
		print_len = spec->precision;
	spec->tot_len += ft_print_padded_uint_base(n, spec, print_len, n_base);
	return (1);
}

/*
** The precision, gives the min number of digits that must appear.
*/

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
	spec->tot_len += ft_print_padded_uint_base(n, spec, print_len, BASE_HEX);
	return (1);
}
