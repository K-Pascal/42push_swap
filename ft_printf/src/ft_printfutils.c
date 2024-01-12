/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:42:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/19 18:07:53 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>

#include "libft/libft.h"

void	padding_char(ssize_t len, char c)
{
	while (len-- > 0)
		write(1, &c, 1);
}

void	ft_putunbr(unsigned long nbr, unsigned int base, int uppercase)
{
	if (nbr >= base)
		ft_putunbr(nbr / base, base, uppercase);
	if (uppercase)
		ft_putchar_fd("0123456789ABCDEF"[nbr % base], 1);
	else
		ft_putchar_fd("0123456789abcdef"[nbr % base], 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		if (nbr <= -10)
			ft_putnbr(-(nbr / 10));
		ft_putchar_fd(-(nbr % 10) + '0', 1);
	}
	else
	{
		if (nbr >= 10)
			ft_putnbr(nbr / 10);
		ft_putchar_fd(nbr % 10 + '0', 1);
	}
}

int	get_numudigits(unsigned long nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

int	get_numdigits(int nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
