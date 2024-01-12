/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfint.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:08 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/11/19 19:22:31 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFINT_H
# define FT_PRINTFINT_H

# include "ft_printfparser.h"
# include "ft_printfints.h"

ssize_t	ft_printfintn(t_info info, int symbol, t_flags flags);
ssize_t	ft_printfintp(t_info info, int symbol, t_flags flags);

#endif
