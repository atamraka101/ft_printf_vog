/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:07:50 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 21:24:44 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function to print hex symbol "0x" or "0X"
*/

int	ft_print_symbol(t_printf_spec *spec)
{
	int	n_printed;

	n_printed = 0;
	if (!spec->fl_hash)
		return (0);
	if (spec->conversion == 'x')
		n_printed += write(1, "0x", 2);
	else if (spec->conversion == 'X')
		n_printed += write(1, "0X", 2);
	spec->fl_hash = 0;
	return (n_printed);
}

/*
** Prints the given unsigned integer as hex string along with
** Zero padding if necessary. Also
** Determines and prints the prepending bytes "0x", "0X" or '0's
** before printing.
*/

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

/*
** Process padding for the printing number as hex.
** Considerations:
** - if hash flag is set, the hex string is prepened
** with two bytes string "0x" for 'x' and "0X" for 'X';
** - minus flag '-' determines padding before or after the hex string.
** in case of padding before, if precision is set then it is always
** padded with space ' '. Otherwise '0' flag determines the padding char.
*/

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
		if (pad_size)
		{
			if (n != 0 && spec->fl_hash && spec->fl_zero)
			{
				n_printed += ft_print_symbol(spec);
				print_len -= 2;
			}
		}
		n_printed += ft_print_pad(spec->fl_zero, pad_size);
	}
	n_printed += ft_print_hex(n, spec, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	return (n_printed);
}

/*
** Processes and prints number as hex according to the given format
** Considerations:
** - if the number is 0 and the precision is explicit 0
** nothing is printed
** - precision influences number of hex bytes to be printed.
** if digits in number is less than the given precision, the
** digits are prepended with 0s
*/

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
	if (spec->dot)
	{
		if (digits < spec->precision)
			print_len = spec->precision;
		spec->fl_zero = 0;
	}
	spec->tot_len += ft_print_padded_hex(n, spec, print_len);
	return (1);
}
