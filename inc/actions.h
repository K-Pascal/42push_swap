/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:41:54 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/05 14:14:38 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "libft/libft.h"

void	swap_elem(t_list **lst);
void	push_elem(t_list **lst_dst, t_list **lst_target);
void	rotate_elem(t_list **lst);
void	reverse_rotate_elem(t_list **lst);

#endif
