/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:40:57 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 23:26:26 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints the given unsigned integer  along with
** Zero padding if necessary.
*/

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
** Process padding for the printing unsigned integer.
** Considerations:
** - minus flag '-' determines padding before or after the hex string.
** in case of padding before, if precision is set then it is always
** padded with space ' '. Otherwise '0' flag determines the padding char.
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
** Processes and prints unsigned integer according to the given format
** Considerations:
** - if the number is 0 and the precision is explicit 0
** nothing is printed
** - precision influences number of digits to be printed.
** if digits in number is less than the given precision, the
** digits are prepended with 0s otherwise the digits in number
** is printed
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
