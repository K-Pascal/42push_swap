/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:59 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/19 18:39:25 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"
#include "ft_printfints.h"

static ssize_t	ft_printfuintpp(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.width > info.precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.precision, ' ');
		padding_char(info.precision - info.len, '0');
		ft_putunbr(info.nbr, 10, 0);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - info.precision, ' ');
		len = info.width;
	}
	else
	{
		padding_char(info.precision - info.len, '0');
		ft_putunbr(info.nbr, 10, 0);
		len = info.precision;
	}
	return (len);
}

static ssize_t	ft_printfuintnp(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.width > info.len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.len, ' ');
		if (info.len > 0)
			ft_putunbr(info.nbr, 10, 0);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - info.len, ' ');
		len = info.width;
	}
	else
	{
		if (info.len > 0)
			ft_putunbr(info.nbr, 10, 0);
		len = info.len;
	}
	return (len);
}

ssize_t	ft_printfuintn(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.width > info.len)
	{
		if (!(flags & ZERO_PADDING) && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.len, ' ');
		if (flags & ZERO_PADDING && !(flags & LEFT_JUSTIFY))
			padding_char(info.width - info.len, '0');
		ft_putunbr(info.nbr, 10, 0);
		if (flags & LEFT_JUSTIFY)
			padding_char(info.width - info.len, ' ');
		len = info.width;
	}
	else
	{
		ft_putunbr(info.nbr, 10, 0);
		len = info.len;
	}
	return (len);
}

ssize_t	ft_printfuintp(t_uinfo info, t_flags flags)
{
	ssize_t	len;

	if (info.precision == 0 && info.nbr == 0)
		info.len = 0;
	if (info.precision > info.len)
		len = ft_printfuintpp(info, flags);
	else
		len = ft_printfuintnp(info, flags);
	return (len);
}
