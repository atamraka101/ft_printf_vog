/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:27:53 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/12 12:19:10 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks if a given character is a printf flag or not.
*/

int	is_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

/*
** parses printf flags.
** considerations: '-' overides '0', and '+' overides ' '
** returns number of bytes processed as there can be consecutive
** flags e.g. "#0"
*/

int	parse_flags(const char *format, t_printf_spec *spec, int pos)
{
	int	ret;

	ret = pos;
	while (is_flag(format[ret]))
	{
		if (format[ret] == '#')
			spec->fl_hash = 1;
		else if (format[ret] == '-')
			spec->fl_minus = 1;
		else if (format[ret] == '+')
			spec->fl_plus = 1;
		else if (format[ret] == '0')
			spec->fl_zero = 1;
		else if (format[ret] == ' ')
			spec->fl_space = 1;
		ret++;
	}
	if (spec->fl_minus)
		spec->fl_zero = 0;
	if (spec->fl_plus)
		spec->fl_space = 0;
	return (ret - pos);
}

/*
** An optional decimal digit string (with nonzero first digit)
** specifying a minimum field width.
** If the converted value has fewer characters than the field width,
** it will be padded with spaces on the left (or right, if the
** left-adjustment flag has been given).
** A negative field width is taken as a '-' flag followed by a positive
** field width.
** A negative field width is taken as a '-' flag followed by a positive field
** width.
** The negative field width case is already handled by '-' flag as '-' preceeds
** width.
** returns number of bytes processed.
**/

int	parse_width(const char *format, va_list args, t_printf_spec *spec, int pos)
{
	int	ret;

	ret = 0;
	if (!*format)
		return (0);
	if (format[pos] == '*')
	{
		spec->width = va_arg(args, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			spec->fl_minus = 1;
		}
		pos++;
		ret++;
	}
	if (ft_isdigit(format[pos]))
	{
		spec->width = ft_atoi(&format[pos]);
		ret += ft_count_nums(&format[pos]);
	}
	return (ret);
}

/*
** An optional precision, in the form of a period ('.')  followed by
** an optional decimal digit string.
** If the precision is given as just '.', the precision is taken to be
** zero.  A negative precision is taken as if the precision were
** omitted.
** returns number of bytes processed.
*/

int	parse_precision(const char *format, va_list args, \
						t_printf_spec *spec, int pos)
{
	if (!*format || format[pos] != '.')
		return (0);
	spec->dot = 1;
	if (format[pos + 1] == '*')
	{
		spec->precision = va_arg(args, int);
		if (spec->precision < 0)
		{
			spec->precision = 0;
			spec->dot = 0;
		}
		return (2);
	}
	else if (!ft_isdigit(format[pos + 1]))
	{
		spec->precision = 0;
		return (1);
	}
	else
	{
		spec->precision = ft_atoi(&format[pos + 1]);
		return (ft_count_nums(&format[pos + 1]) + 1);
	}
}

/*
** Parses length modifier
** returns number of bytes processed e.g. 'l' one byte, 'll' two bytes
*/

int	parse_length_modifier(const char *format, t_printf_spec *spec, int pos)
{
	int	ret;

	ret = 1;
	if (!*format || (format[pos] != 'h' && format[pos] != 'l' \
		&& format[pos] != 'L'))
		return (0);
	if (format[pos] == 'h' && format[pos + 1] != 'h')
		spec->len_modifier = LM_H;
	else if (format[pos] == 'h' && format[pos + 1] == 'h')
	{
		spec->len_modifier = LM_HH;
		ret = 2;
	}
	else if (format[pos] == 'l' && format[pos + 1] != 'l')
		spec->len_modifier = LM_L;
	else if (format[pos] == 'l' && format[pos + 1] == 'l')
	{
		spec->len_modifier = LM_LL;
		ret = 2;
	}
	else if (format[pos] == 'L')
		spec->len_modifier = LM_LD;
	return (ret);
}
