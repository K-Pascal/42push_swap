/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:00:17 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/29 19:30:07 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

typedef unsigned int	t_uint;

int		ft_printf(char const format[], ...);

typedef struct s_nums
{
	t_uint	width;
	ssize_t	precision;
}	t_nums;

#endif
