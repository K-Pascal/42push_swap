/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:39:06 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 15:13:17 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

static void	swap_elem(t_list **lst)
{
	t_list	*first;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = (*lst)->next;
	(*lst)->next = first->next;
	first->next = *lst;
	*lst = first;
}

static void	push_elem(t_list **lst_dst, t_list **lst_target)
{
	t_list	*elem;

	if (*lst_target == NULL)
		return ;
	elem = *lst_target;
	*lst_target = elem->next;
	ft_lstadd_front(lst_dst, elem);
}

static void	rotate_elem(t_list **lst)
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

static void	reverse_rotate_elem(t_list **lst)
{
	int	len;

	len = ft_lstsize(*lst);
	if (len <= 1)
		return ;
	while (--len)
		rotate_elem(lst);
}

void	set_command(t_list **lst_a, t_list **lst_b, char cmd[], int len)
{
	if (len == 2)
	{
		if (!ft_strncmp(cmd, "ss", 2) || !ft_strncmp(cmd, "sa", 2))
			swap_elem(lst_a);
		if (!ft_strncmp(cmd, "ss", 2) || !ft_strncmp(cmd, "sb", 2))
			swap_elem(lst_b);
		if (!ft_strncmp(cmd, "pa", 2))
			push_elem(lst_a, lst_b);
		if (!ft_strncmp(cmd, "pb", 2))
			push_elem(lst_b, lst_a);
		if (!ft_strncmp(cmd, "rr", 2) || !ft_strncmp(cmd, "ra", 2))
			rotate_elem(lst_a);
		if (!ft_strncmp(cmd, "rr", 2) || !ft_strncmp(cmd, "rb", 2))
			rotate_elem(lst_b);
	}
	else
	{
		if (!ft_strncmp(cmd, "rrr", 3) || !ft_strncmp(cmd, "rra", 3))
			reverse_rotate_elem(lst_a);
		if (!ft_strncmp(cmd, "rrr", 3) || !ft_strncmp(cmd, "rrb", 3))
			reverse_rotate_elem(lst_b);
	}
	ft_putendl_fd(cmd, 1);
}
