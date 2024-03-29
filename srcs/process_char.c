/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:38:49 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 18:07:47 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Processes and prints a given character according to the given format.
** width determines the size of print value,
** Since char is one byte, rest of the size is padded with SPACE ' '
** (right justification.).
** If '-' Flag is set, value is printed only after padding. (Left justification)
*/

int	ft_process_char(va_list args, t_printf_spec *spec)
{
	char	a;

	a = (char)va_arg(args, int);
	if (spec->width && !spec->fl_minus)
		spec->tot_len += ft_print_pad(spec->fl_zero, spec->width - 1);
	spec->tot_len += write(1, &a, 1);
	if (spec->width && spec->fl_minus)
		spec->tot_len += ft_print_pad(0, spec->width - 1);
	return (1);
}
