/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:59:06 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:09:23 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_power_double(long double base, int power)
{
	int			i;
	long double	n;

	i = 0;
	n = 1.0;
	while (i < power)
	{
		n *= base;
		i++;
	}
	return (n);
}

long double	ft_round(long double num, int i)
{
	long double	round_num;
	long double	dec;

	dec = 0.5;
	while (i > 0)
	{
		dec = dec / 10;
		i--;
	}
	if (num >= 0)
		round_num = num + dec;
	else
		round_num = num - dec;
	return (round_num);
}

/*
** checks if we need to add sign in front of float value
** sign is added if given number is negative i.e. n < 0, or
** if PLUS '+' flag is set
** We also need to add a space, if SPACE ' ' flag is set
*/

int	check_sign_float(long double n, t_printf_spec *spec, char *c)
{
	if (n < 0.0 || spec->fl_plus || spec->fl_space)
	{
		if (n < 0.0)
			*c = '-';
		else if (spec->fl_plus)
			*c = '+';
		else
			*c = ' ';
		return (1);
	}
	*c = '\0';
	return (0);
}

/*
** checks if we need to add sign in front of integer value
** sign is added if given number is negative i.e. n < 0, or
** if PLUS '+' flag is set
** We also need to add a space, if SPACE ' ' flag is set
*/

int	check_sign(long long int n, t_printf_spec *spec, char *c)
{
	if (n < 0 || spec->fl_plus || spec->fl_space)
	{
		if (n < 0)
			*c = '-';
		else if (spec->fl_plus)
			*c = '+';
		else
			*c = ' ';
		return (1);
	}
	*c = '\0';
	return (0);
}
