/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_length_modifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:46:49 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 18:49:09 by atamraka         ###   ########.fr       */
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
		return ((long long int)((short int) va_arg(args, int)));
	else if (spec->len_modifier == LM_HH)
		return ((long long int)((signed char) va_arg(args, int)));
	else if (spec->len_modifier == LM_L)
		return ((long long int)((long int) va_arg(args, long int)));
	else if (spec->len_modifier == LM_LL)
		return ((long long int) va_arg(args, long long int));
	else
		return ((long long int)(int) va_arg(args, int));
}

/*
** Returns unsigned int data type based on the lenght modifier
**
*/

unsigned long long int	ft_treat_uint_length_modifier(va_list args, \
														t_printf_spec *spec)
{
	if (spec->len_modifier == LM_H)
		return ((unsigned long long int)((unsigned short int) \
					va_arg(args, int)));
	else if (spec->len_modifier == LM_HH)
		return ((unsigned long long int)((unsigned char) va_arg(args, int)));
	else if (spec->len_modifier == LM_L)
		return ((unsigned long long int)va_arg(args, unsigned long int));
	else if (spec->len_modifier == LM_LL)
		return ((unsigned long long int) va_arg(args, unsigned long long int));
	else
		return ((unsigned long long int)va_arg(args, unsigned int));
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
		return ((long double)((double)va_arg(args, double)));
}
