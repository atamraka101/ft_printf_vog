/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:26:20 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:29 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** counts the number of digits in a given signed int
** and retuns the total digits  
*/

int	ft_count_digits(long long int nbr)
{
	int				digits;
	long long int	lln;

	digits = 0;
	if (nbr == 0)
		return (1);
	lln = nbr;
	if (lln < 0)
		lln = lln * (-1);
	while (lln > 0)
	{
		lln /= 10;
		digits++;
	}
	return (digits);
}

/*
** counts the number of digits in a given unsigned int
** and retuns the total digits  
*/

int	count_digits_unsig_base(unsigned long long int n, int n_base)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		n /= n_base;
		digits++;
	}
	return (digits);
}

/*
** Calculates the length of pad that needed to be added
** Pad is determined by width - printable characters
*/
int	ft_get_pad_size(int width, int print_len)
{
	int	pad_size;

	pad_size = 0;
	if (width > print_len)
		pad_size = width - print_len;
	return (pad_size);
}
