/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_length_modifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:46:49 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 12:45:38 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns signed int data type based on the lenght modifier
**
*/

long long int	ft_treat_int_length_modifier(va_list args, t_printf_spec *spec)
{
	if (spec->len_modifier == LM_H)
		return ((short int) va_arg(args, int));
	else if (spec->len_modifier == LM_HH)
		return ((char) va_arg(args, int));
	else if (spec->len_modifier == LM_L)
		return ((long)va_arg(args, long int));
	else if (spec->len_modifier == LM_LL)
		return (va_arg(args, long long int));
	else
		return ((int) va_arg(args, int));
}

/*
** Returns unsigned int data type based on the lenght modifier
**
*/

unsigned long long int	ft_treat_uint_length_modifier(va_list args, \
														t_printf_spec *spec)
{
	if (spec->len_modifier == LM_H)
		return ((unsigned short int)va_arg(args, unsigned int));
	else if (spec->len_modifier == LM_HH)
		return ((unsigned char)va_arg(args, unsigned int));
	else if (spec->len_modifier == LM_L)
		return ((unsigned long)va_arg(args, unsigned long int));
	else if (spec->len_modifier == LM_LL)
		return (va_arg(args, unsigned long long int));
	else
		return ((unsigned int)va_arg(args, unsigned int));
}

/*
** Returns signed float data type based on the lenght modifier
**
*/

long double	ft_treat_float_length_modifier(va_list args, t_printf_spec *spec)
{
	if (spec->len_modifier == LM_LD)
		return ((long double)va_arg(args, long double));
	else
		return ((double)va_arg(args, double));
}
