/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:37:03 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/18 17:44:26 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>

#include "ft_printf.h"
#include "ft_printfparser.h"
#include "ft_printfints.h"
#include "ft_printfint.h"
#include "ft_printfuint.h"
#include "ft_printfhex.h"

ssize_t	ft_printfint(va_list ap, t_flags flags, t_uint width, ssize_t precision)
{
	t_info	info;
	ssize_t	len;
	int		symbol;

	info.nbr = va_arg(ap, int);
	info.len = get_numdigits(info.nbr, 10);
	info.width = width;
	info.precision = precision;
	symbol = 0;
	if (info.nbr < 0 || flags & SIGN_SYMBOL
		|| (flags & SPACE_SIGN && (info.nbr >= 0 || flags & ZERO_PADDING)))
		symbol = 1;
	if (info.precision == -1)
		len = ft_printfintn(info, symbol, flags);
	else
		len = ft_printfintp(info, symbol, flags);
	return (len);
}

ssize_t	ft_printfuint(va_list ap, t_flags flags, t_uint width, ssize_t p)
{
	t_uinfo	info;
	ssize_t	len;

	info.nbr = va_arg(ap, t_uint);
	info.len = get_numudigits(info.nbr, 10);
	info.width = width;
	info.precision = p;
	if (info.precision == -1)
		len = ft_printfuintn(info, flags);
	else
		len = ft_printfuintp(info, flags);
	return (len);
}

ssize_t	ft_printfhex(va_list ap, t_flags flags, t_uint width, ssize_t precision)
{
	t_uinfo	info;
	ssize_t	len;
	int		symbol;

	info.nbr = va_arg(ap, t_uint);
	info.len = get_numudigits(info.nbr, 16);
	info.width = width;
	info.precision = precision;
	symbol = (flags & ALTERNATE_FORM && info.nbr != 0) * 2;
	if (info.precision == -1)
		len = ft_printfhexn(info, flags, symbol, 0);
	else
		len = ft_printfhexp(info, flags, symbol, 0);
	return (len);
}

ssize_t	ft_printfhexu(va_list ap, t_flags flags, t_uint width, ssize_t p)
{
	t_uinfo	info;
	ssize_t	len;
	int		symbol;

	info.nbr = va_arg(ap, t_uint);
	info.len = get_numudigits(info.nbr, 16);
	info.width = width;
	info.precision = p;
	symbol = (flags & ALTERNATE_FORM && info.nbr != 0) * 2;
	if (info.precision == -1)
		len = ft_printfhexn(info, flags, symbol, 1);
	else
		len = ft_printfhexp(info, flags, symbol, 1);
	return (len);
}
