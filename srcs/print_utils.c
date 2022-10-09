/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:33:23 by atamraka          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:39 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_pad(int zero, int size)
{
	int		i;
	char	c;

	if (zero)
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
