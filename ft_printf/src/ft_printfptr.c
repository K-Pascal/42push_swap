/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:29:05 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/18 17:42:47 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>

#include "libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"

static ssize_t	ft_printfhexnull(t_flags flags, t_uint width)
{
	ssize_t	len;

	len = 5;
	if (width > len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(width - len, ' ');
		write(1, "(nil)", 5);
		if (flags & LEFT_JUSTIFY)
			padding_char(width - len, ' ');
		len = width;
	}
	else
		write(1, "(nil)", 5);
	return (len);
}

ssize_t	ft_printfptr(va_list ap, t_flags flags, t_uint width)
{
	void			*ptr;
	ssize_t			len;
	unsigned long	lptr;

	ptr = va_arg(ap, void *);
	if (ptr == 0)
		return (ft_printfhexnull(flags, width));
	lptr = (unsigned long)ptr;
	len = get_numudigits(lptr, 16) + 2;
	if (width > len)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(width - len, ' ');
		write(1, "0x", 2);
		ft_putunbr(lptr, 16, 0);
		if (flags & LEFT_JUSTIFY)
			padding_char(width - len, ' ');
		len = width;
	}
	else
	{
		write(1, "0x", 2);
		ft_putunbr(lptr, 16, 0);
	}
	return (len);
}
