/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:02 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 23:56:40 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints error string for string type:
** when the give input is NULL: "(null)" is printed
*/

int	ft_print_err(char *err_str, t_printf_spec *spec)
{
	int	pad_size;
	int	print_len;
	int	n_printed;

	n_printed = 0;
	pad_size = 0;
	print_len = ft_strlen(err_str);
	if (spec->dot && (print_len > spec->precision))
		print_len = spec->precision;
	if (spec->width > print_len)
		pad_size = spec->width - print_len;
	if (!spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	n_printed += write(1, err_str, print_len);
	if (spec->fl_minus)
		n_printed += ft_print_pad(0, pad_size);
	return (n_printed);
}

/*
** Prints error string for float type
** [-]inf or nan
*/

int	ft_print_float_err(long double n, t_printf_spec *spec)
{
	if (n != n)
		return (ft_print_err(ERR_NAN, spec));
	else if (n == (-1.0 / 0.0))
		return (ft_print_err(ERR_INF_NEG, spec));
	else if (n == (1.0 / 0.0))
		return (ft_print_err(ERR_INF, spec));
	else
		return (0);
}

/*
** Processes and prints string.
** Flag: The converted value is to be left adjusted on the field
**       boundary.  (The default is right justification.)
** Width: An optional decimal digit string (with nonzero first digit)
**      specifying a minimum field width.  If the converted value has
**      fewer characters than the field width, it will be padded with
**      spaces on the left (or right, if the left-adjustment flag i.e. '-'
**      has been given).
** Precision: Represented by dot '.' followed by a number. If no number is given
** precision value is treated as 0.
*/

int	ft_process_string(va_list args, t_printf_spec *spec)
{
	int		pad_size;
	char	*str;
	int		print_len;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		spec->tot_len += ft_print_err(ERR_NULL_STRING, spec);
		return (1);
	}
	print_len = ft_strlen(str);
	if (spec->dot && print_len > spec->precision)
		print_len = spec->precision;
	pad_size = 0;
	if (spec->width > print_len)
		pad_size = spec->width - print_len;
	if (!spec->fl_minus)
		spec->tot_len += ft_print_pad(0, pad_size);
	spec->tot_len += write(1, str, print_len);
	if (spec->fl_minus)
		spec->tot_len += ft_print_pad(0, pad_size);
	return (1);
}
