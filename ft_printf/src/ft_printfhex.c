/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:43:41 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/05 13:59:47 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"
#include "ft_printfints.h"

static void	ft_printfhexprefix(unsigned int nbr, t_flags flags, int uppercase)
{
	if (flags & ALTERNATE_FORM && nbr != 0)
	{
		if (uppercase)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
}

static ssize_t	ft_printfhexpp(t_uinfo info, t_flags flags, int sym, int upper)
{
	ssize_t	len;

	if (info.width > info.precision + sym)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.precision + sym), ' ');
		ft_printfhexprefix(info.nbr, flags, upper);
		padding_char(info.precision - info.len, '0');
		ft_putunbr(info.nbr, 16, upper);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - (info.precision + sym), ' ');
		len = info.width;
	}
	else
	{
		ft_printfhexprefix(info.nbr, flags, upper);
		padding_char(info.precision - info.len, '0');
		ft_putunbr(info.nbr, 16, upper);
		len = info.precision + sym;
	}
	return (len);
}

static ssize_t	ft_printfhexnp(t_uinfo info, t_flags flags, int sym, int upper)
{
	ssize_t	len;

	if (info.width > info.len + sym)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.len + sym), ' ');
		ft_printfhexprefix(info.nbr, flags, upper);
		if (info.len > 0)
			ft_putunbr(info.nbr, 16, upper);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - (info.len + sym), ' ');
		len = info.width;
	}
	else
	{
		ft_printfhexprefix(info.nbr, flags, upper);
		if (info.len > 0)
			ft_putunbr(info.nbr, 16, upper);
		len = info.len + sym;
	}
	return (len);
}

ssize_t	ft_printfhexn(t_uinfo info, t_flags flags, int symbol, int uppercase)
{
	ssize_t	len;

	if (info.width > info.len + symbol)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.len + symbol), ' ');
		ft_printfhexprefix(info.nbr, flags, uppercase);
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - (info.len + symbol), '0');
		ft_putunbr(info.nbr, 16, uppercase);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - (info.len + symbol), ' ');
		len = info.width;
	}
	else
	{
		ft_printfhexprefix(info.nbr, flags, uppercase);
		ft_putunbr(info.nbr, 16, uppercase);
		len = info.len + symbol;
	}
	return (len);
}

ssize_t	ft_printfhexp(t_uinfo info, t_flags flags, int symbol, int uppercase)
{
	ssize_t	len;

	if (info.precision == 0 && info.nbr == 0)
		info.len = 0;
	if (info.precision > info.len)
		len = ft_printfhexpp(info, flags, symbol, uppercase);
	else
		len = ft_printfhexnp(info, flags, symbol, uppercase);
	return (len);
}
