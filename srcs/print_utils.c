/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:33:23 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/11 09:28:06 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Recursive function that prints given integer
*/

int	ft_print_nbr(long long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr < 0)
		nbr = nbr * (-1);
	if (nbr >= BASE_DECIMAL)
	{
		ret += ft_print_nbr(nbr / BASE_DECIMAL);
		ret += ft_print_nbr(nbr % BASE_DECIMAL);
	}
	else
		ret += write(1, &BASE_CHARACTERS[nbr], 1);
	return (ret);
}

/*
** Recursive function that prints given unsigned integer depending
** upon given base. BASE 10 for unsigned int, BASE 8 for octal
** and BASE 16 for HEX.
*/

int	ft_print_unbr_base(unsigned long long int nbr, int base_n, char *s)
{
	int	ret;

	ret = 0;
	if (nbr >= (unsigned long long)base_n)
	{
		ret += ft_print_unbr_base(nbr / base_n, base_n, s);
		ret += ft_print_unbr_base(nbr % base_n, base_n, s);
	}
	else
		ret += write(1, &s[nbr], 1);
	return (ret);
}

/*
** Prints pad bytes of given size
** if parameter pad_zero is set, the function pads with '0'
** otherwise pads with space characters ' '.
*/

int	ft_print_pad(int pad_zero, int size)
{
	int		i;
	char	c;

	if (pad_zero)
		c = '0';
	else
		c = ' ';
	i = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}
