/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percentage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:54:20 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 19:04:53 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Processes and prints '%'.
** Flags, width, precision are not considered while
** processing '%'.
*/

int	ft_process_percentage(t_printf_spec *spec)
{
	spec->tot_len += write(1, "%", 1);
	return (1);
}
