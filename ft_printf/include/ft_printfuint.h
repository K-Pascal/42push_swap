/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuint.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:19 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/19 19:23:43 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFUINT_H
# define FT_PRINTFUINT_H

# include "ft_printfparser.h"
# include "ft_printfints.h"

ssize_t	ft_printfuintn(t_uinfo info, t_flags flags);
ssize_t	ft_printfuintp(t_uinfo info, t_flags flags);

#endif
