/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:04:10 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 20:12:09 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_spec	*ft_initialize_spec(t_printf_spec *spec)
{
	spec->fl_hash = 0;
	spec->fl_zero = 0;
	spec->fl_minus = 0;
	spec->fl_plus = 0;
	spec->fl_space = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->dot = 0;
	spec->len_modifier = 0;
	spec->conversion = '\0';
	spec->tot_len = 0;
	return (spec);
}

int	ft_conversion(char c, va_list args, t_printf_spec *spec)
{
	spec->conversion = c;
	if (c == 'c')
		return (ft_process_char(args, spec));
	else if (c == 's')
		return (ft_process_string(args, spec));
	else if (c == 'd' || c == 'i')
		return (ft_process_int(args, spec));
	else if (c == 'u')
		return (ft_process_uint(args, spec));
	else if (c == 'x' || c == 'X')
		return (ft_process_hex(args, spec));
	else if (c == 'o')
		return (ft_process_octal(args, spec));
	else if (c == 'p')
		return (ft_process_pointer(args, spec));
	else if (c == 'f')
		return (ft_process_float(args, spec));
	else if (c == '%')
		return (ft_process_percentage(spec));
	return (0);
}

int	ft_eval_format(const char *format, \
						va_list args, t_printf_spec *spec, int pos)
{
	int	ret;

	ret = pos;
	ft_initialize_spec(spec);
	ret += parse_flags(format, spec, ret);
	ret += parse_width(format, args, spec, ret);
	ret += parse_precision(format, args, spec, ret);
	ret += parse_length_modifier(format, spec, ret);
	ret += ft_conversion(format[ret], args, spec);
	return (ret - pos);
}

int	ft_process_printf(const char *format, va_list args, t_printf_spec *spec)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += ft_eval_format(format, args, spec, i + 1) + 1;
			ret += spec->tot_len;
		}
		else
		{
			ret += write(1, &format[i], 1);
			i++;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				ret;
	t_printf_spec	*spec;
	va_list			args;

	spec = (t_printf_spec *)malloc(sizeof(t_printf_spec));
	if (!spec)
		return (-1);
	ft_initialize_spec(spec);
	va_start(args, format);
	i = 0;
	ret = ft_process_printf(format, args, spec);
	free(spec);
	va_end(args);
	return (ret);
}
