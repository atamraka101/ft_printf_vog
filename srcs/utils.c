/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:59:06 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 21:16:26 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Calculates and returns the nth power of the
** given base. nth power is determined by
** parameter "power"
*/

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

/*
** Rounds the given double data type.
*/

long double	ft_round(long double n, int i)
{
	long double	round_n;
	long double	dec;

	dec = 0.5;
	while (i > 0)
	{
		dec = dec / 10;
		i--;
	}
	if (n >= 0)
		round_n = n + dec;
	else
		round_n = n - dec;
	return (round_n);
}

/*
** Function to check if given double is negative
**
*/
int	ft_is_neg(double n)
{
	long long int	*hold;
	char			sign;

	hold = (long long int *)&n;
	sign = (char)(*hold >> 63);
	if (sign == 0)
		return (0);
	else
		return (1);
}

/*
** checks if we need to add sign in front of float value
** sign is added if given number is negative i.e. n < 0, or
** if PLUS '+' flag is set
** We also need to add a space, if SPACE ' ' flag is set
*/

int	check_sign_float(long double n, t_printf_spec *spec, char *c)
{
	if (ft_is_neg(n) || (spec->fl_plus) || (spec->fl_space))
	{
		if (ft_is_neg(n))
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
** This function returns the number of chars that represents a number
** in the given string
*/

int	ft_count_nums(const char *str)
{
	int	n;

	n = 0;
	while (ft_isdigit(str[n]))
		n++;
	return (n);
}
