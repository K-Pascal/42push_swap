/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:33 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/19 18:08:36 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFUTILS_H
# define FT_PRINTFUTILS_H

# include <sys/types.h>

# include "ft_printf.h"

void	padding_char(ssize_t len, char c);
void	ft_putunbr(unsigned long nbr, unsigned int base, int uppercase);
int		get_numudigits(unsigned long nbr, int base);
int		get_numdigits(int nbr, int base);
void	ft_putnbr(int nbr);

#endif
