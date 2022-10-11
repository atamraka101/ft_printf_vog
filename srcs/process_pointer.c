/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:48:27 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 19:00:43 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints the given pointer value as hex string along with
** Zero padding if necessary. Also
** Determines and prints the prepending bytes "0x"
** before printing.
*/

int	ft_print_pointer(unsigned long int n, t_printf_spec *spec, int print_len)
{
	int	digits;
	int	n_printed;

	n_printed = 0;
	if (spec->fl_hash)
		n_printed = write(1, "0x", 2);
	digits = count_digits_unsig_base(n, BASE_HEX);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_unbr_base(n, BASE_HEX, BASE_CHARACTERS);
	return (n_printed);
}

/*
** Process padding for the pointer printed as hex string.
** Considerations:
** - minus flag '-' determines padding before or after the hex string.
** in case of padding before, if precision is set then it is always
** padded with space ' '. Otherwise '0' flag determines the padding char.
*/

int	ft_print_padded_pointer(unsigned long int n, t_printf_spec *spec, \
							int print_len)
{
	int	pad_size;
	int	n_printed;

	n_printed = 0;
	pad_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if (spec->dot)
			n_printed += ft_print_pad(0, pad_size);
		else if (pad_size)
		{
			if (spec->fl_zero)
			{
				n_printed += write(1, "0x", 2);
				print_len -= 2;
				spec->fl_hash = 0;
			}
			n_printed += ft_print_pad(spec->fl_zero, pad_size);
		}
	}
	n_printed += ft_print_pointer(n, spec, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	return (n_printed);
}

/*
** Processes and prints pointer according to the given format
** Pointers are printed as hex 'x' therefore reuses sub-functions
** for printing hex.
** Considerations:
** - if the supplied pointer is NULL, it prints
** string "0x0" as an error.
** - if the pointer is 0 and the precision is explicit 0
** "0x" is printed
*/

int	ft_process_pointer(va_list args, t_printf_spec *spec)
{
	unsigned long	n;
	int				digits;
	int				print_len;

	n = (unsigned long int)va_arg(args, unsigned long int);
	if (!n || n == 0)
		n = 0;
	if (n == 0 && (spec->dot && spec->precision == 0))
		digits = 0;
	else
		digits = count_digits_unsig_base(n, BASE_HEX);
	print_len = digits;
	if (spec->dot && (digits < spec->precision))
		print_len = spec->precision;
	spec->fl_hash = 1;
	spec->tot_len += ft_print_padded_pointer(n, spec, print_len + 2);
	return (1);
}
