/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:49:52 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 19:04:33 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints the given signed integer along with
** Zero padding if necessary.
*/

int	ft_print_int(long long int n, t_printf_spec *spec, int print_len)
{
	char	sign;
	int		digits;
	int		n_printed;

	n_printed = 0;
	check_sign(n, spec, &sign);
	if (sign != '\0')
		n_printed += write(1, &sign, 1);
	digits = ft_count_digits(n);
	while ((n_printed + digits) < print_len)
		n_printed += write(1, "0", 1);
	if (n_printed < print_len)
		n_printed += ft_print_nbr(n);
	return (n_printed);
}

/*
** A sub function to simply print signs prior to padding
** with zero. The functions unsets plus and space flags
** for further processing.
*/
int	ft_print_sign_bf_pad(char sign, t_printf_spec *spec)
{
	int	n_printed;

	n_printed = write(1, &sign, 1);
	spec->fl_plus = 0;
	spec->fl_space = 0;
	return (n_printed);
}

/*
** Process padding for the printing signed int.
** Considerations:
** check for negative sign and explicit '+' sign based on '#' flag
** - minus flag '-' determines padding before or after the hex string.
** in case of padding before, if precision is set then it is always 
** padded with space ' '. Otherwise '0' flag determines the padding char.
** output conditions:
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
	fill_size = ft_get_pad_size(spec->width, print_len);
	if (!spec->fl_minus)
	{
		if ((sign != '\0') & spec->fl_zero && !spec->precision)
		{
			n_printed += ft_print_sign_bf_pad(sign, spec);
			if (n < 0)
				n = n * (-1);
			print_len--;
		}
		if (spec->precision)
			n_printed += ft_print_pad(0, fill_size);
		else
			n_printed += ft_print_pad(spec->fl_zero, fill_size);
	}
	n_printed += ft_print_int(n, spec, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(spec->fl_zero, fill_size);
	return (n_printed);
}

/*
** Processes and prints signed integer according to the given format
** Considerations: 
** - if the number is 0 and the precision is explicit 0
** nothing is printed
** - precision influences number of digits to be printed.
** if digits in number is less than the given precision, the 
** digits are prepended with 0s
*/

int	ft_process_int(va_list args, t_printf_spec *spec)
{
	long long int	n;
	int				digits;
	int				print_len;

	n = ft_treat_int_length_modifier(args, spec);
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
