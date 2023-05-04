/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:25:59 by abarbieu          #+#    #+#             */
/*   Updated: 2023/04/25 13:26:47 by abarbieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_totlen(unsigned int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_put_un_int(unsigned int nb)
{
	if (nb < 0)
	{
		nb = 4294967296 - nb;
	}
	if (nb <= 9)
		ft_c(nb + '0');
	if (nb > 9)
	{
		ft_put_un_int(nb / 10);
		ft_put_un_int(nb % 10);
	}
	return (ft_totlen(nb));
}
