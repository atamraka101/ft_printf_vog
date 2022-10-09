/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percentage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:54:20 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:09:04 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_percentage(t_printf_spec *spec)
{
	if (!spec->fl_minus)
		spec->tot_len += ft_print_pad(spec->fl_zero, spec->width - 1);
	spec->tot_len += write(1, "%", 1);
	if (spec->fl_minus)
		spec->tot_len += ft_print_pad(spec->fl_zero, spec->width - 1);
	return (1);
}
