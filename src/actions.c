/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:39:06 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/13 16:27:40 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

#include "inc/actions_utils.h"

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
	len = ft_strlen(cmd);
	if (!ft_strncmp(cmd, "ss", my_max(len, 2))
		|| !ft_strncmp(cmd, "sa", my_max(len, 2)))
		swap_elem(lst_a);
	if (!ft_strncmp(cmd, "ss", my_max(len, 2))
		|| !ft_strncmp(cmd, "sb", my_max(len, 2)))
		swap_elem(lst_b);
	if (!ft_strncmp(cmd, "pa", my_max(len, 2)))
		push_elem(lst_a, lst_b);
	if (!ft_strncmp(cmd, "pb", my_max(len, 2)))
		push_elem(lst_b, lst_a);
	if (!ft_strncmp(cmd, "rr", my_max(len, 2))
		|| !ft_strncmp(cmd, "ra", my_max(len, 2)))
		rotate_elem(lst_a);
	if (!ft_strncmp(cmd, "rr", my_max(len, 2))
		|| !ft_strncmp(cmd, "rb", my_max(len, 2)))
		rotate_elem(lst_b);
	if (!ft_strncmp(cmd, "rrr", my_max(len, 3))
		|| !ft_strncmp(cmd, "rra", my_max(len, 3)))
		reverse_rotate_elem(lst_a);
	if (!ft_strncmp(cmd, "rrr", my_max(len, 3))
		|| !ft_strncmp(cmd, "rrb", my_max(len, 3)))
		reverse_rotate_elem(lst_b);
	ft_putendl_fd(cmd, 1);
}
