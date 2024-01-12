/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:33:52 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/05 13:53:28 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfutils.h"

ssize_t	ft_printfnullstr(t_flags flags, t_uint width, ssize_t precision)
{
	if (precision != -1 && precision < 6)
		precision = 0;
	else if (precision == -1 || precision > 6)
		precision = 6;
	if (width > precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(width - precision, ' ');
		write(1, "(null)", precision);
		if (flags & LEFT_JUSTIFY)
			padding_char(width - precision, ' ');
	}
	else
	{
		write(1, "(null)", precision);
		return (precision);
	}
	return (width);
}

ssize_t	ft_printfchar(va_list ap, t_flags flags, t_uint width)
{
	char	c;
	ssize_t	len;

	c = va_arg(ap, int);
	len = 0;
	if (width > 1)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(width - 1, ' ');
		len += write(1, &c, 1);
		if (flags & LEFT_JUSTIFY)
			padding_char(width - 1, ' ');
		len += width - 1;
	}
	else
		len += write(1, &c, 1);
	return (len);
}

ssize_t	ft_printfstr(va_list ap, t_flags flags, t_uint width, ssize_t precision)
{
	char const	*str;
	size_t		len_s;
	ssize_t		len;

	len = 0;
	str = va_arg(ap, char const *);
	if (str == 0)
		return (ft_printfnullstr(flags, width, precision));
	len_s = ft_strlen(str);
	if (precision == -1 || len_s < (size_t)precision)
		precision = len_s;
	if (width > precision)
	{
		if (!(flags & LEFT_JUSTIFY))
			padding_char(width - precision, ' ');
		len += write(1, str, precision);
		if (flags & LEFT_JUSTIFY)
			padding_char(width - precision, ' ');
		len += width - precision;
	}
	else
		len += write(1, str, precision);
	return (len);
}
