/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:39:06 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/05 14:14:54 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

void	swap_elem(t_list **lst)
{
	t_list	*first;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = (*lst)->next;
	(*lst)->next = first->next;
	first->next = *lst;
	*lst = first;
}

void	push_elem(t_list **lst_dst, t_list **lst_target)
{
	t_list	*elem;

	if (*lst_target == NULL)
		return ;
	elem = *lst_target;
	*lst_target = (*lst_target)->next;
	ft_lstadd_front(lst_dst, elem);
}

void	rotate_elem(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	first = last->next;
	last->next = NULL;
	ft_lstlast(first)->next = last;
	*lst = first;
}

void	reverse_rotate_elem(t_list **lst)
{
	int	len;

	len = ft_lstsize(*lst);
	if (len <= 1)
		return ;
	while (--len)
		rotate_elem(lst);
}
