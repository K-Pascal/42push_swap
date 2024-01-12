/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:59:11 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 17:17:26 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTS_UTILS_H
# define SORTS_UTILS_H

# include "libft/libft.h"

typedef enum e_actions
{
	SWAP = (1 << 0),
	ROTATE = (1 << 1),
	REVERSE_ROTATE = (1 << 2)
}	t_actions;

int		findmax(t_list *stack);
void	do_actions(t_list **s_a, t_list **s_b, t_actions a_a, t_actions a_b);
void	push_values(t_list **stack_a, t_list **stack_b, int size_a);
void	goto_minvalue(t_list **stack_a);
int		findzero(t_list *stack);
void	bitshiftvalue(void *content);

#endif
