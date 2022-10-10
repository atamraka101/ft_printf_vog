/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:08:05 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/10 19:08:07 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** converts the integer digits (before decimal points) of a given float 
** to a string
*/

char	*ft_ftoa_int_digits(long double n)
{
	char		*str;
	long double	hold;
	int			i;
	int			str_count;

	i = 0;
	str_count = 0;
	hold = n;
	while (hold >= 10)
	{
		hold /= 10;
		str_count ++;
	}
	str = ft_strnew(str_count + 1);
	if (!str)
		return (NULL);
	while (str_count >= 0)
	{
		hold = n / ft_power_double(10, str_count);
		str[i++] = (long long)hold + '0';
		n -= ((long long)hold * ft_power_double(10.00, str_count));
		str_count--;
	}
	return (str);
}

/*
** converts the fraction digits (after decimal point) of a given float
** to a string. This function also adds '.' infront of the fraction
** digits.
*/

char	*ft_ftoa_frac_digits(long double n, int precision)
{
	char		*str;
	long double	hold;
	int			i;
	int			count;

	i = 0;
	hold = n - (long int)n;
	count = precision + 1;
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	str[i++] = '.';
	while (i < count)
	{
		hold *= 10;
		str[i++] = (long long)hold + '0';
		hold -= (long long)hold;
	}
	return (str);
}

/*
** convetrts the a given float to a string
** This function calls two sub-functions:
** ft_ftoa_int_digits to extract the integer part 
** of the float to string, and ft_ftoa_frac_digits
** to extract the integer part of the float.
** This function joins the results from two previous
** sub-function to convert float to string.
** Edge case: If precision is explicitly 0 then it 
** doesn't print fraction part unless # flag is given,
** in which case it simply prints '.' after the integer
** part
*/

char	*ft_ftoa(long double n, t_printf_spec *spec)
{
	char	*str;
	char	*str_int;
	char	*str_frac;

	str_int = ft_ftoa_int_digits(n);
	if (spec->precision == 0)
	{
		if (spec->fl_hash)
			str_frac = ft_strdup(".");
		else
			str_frac = ft_strdup("");
	}
	else
		str_frac = ft_ftoa_frac_digits(n, spec->precision);
	str = ft_strjoin(str_int, str_frac);
	free(str_int);
	free(str_frac);
	return (str);
}
