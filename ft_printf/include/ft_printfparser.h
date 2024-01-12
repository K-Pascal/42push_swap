/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfparser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:25:07 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/19 18:44:16 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFPARSER_H
# define FT_PRINTFPARSER_H

typedef enum e_flags
{
	LEFT_JUSTIFY = (1 << 0),
	SIGN_SYMBOL = (1 << 1),
	SPACE_SIGN = (1 << 2),
	ALTERNATE_FORM = (1 << 3),
	ZERO_PADDING = (1 << 4)
}	t_flags;

t_flags			ft_printf_getflags(char const str[], int *i);
unsigned int	ft_printf_atoi(char const str[], int *i);
#endif
