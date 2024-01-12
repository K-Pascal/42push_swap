/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/04 18:16:56 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdlib.h>

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

void	print_elem(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

void	visualize(t_list *lst_a, t_list *lst_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(lst_a);
	size_b = ft_lstsize(lst_b);
	while (lst_a != NULL || lst_b != NULL)
	{
		if (size_a > size_b)
		{
			ft_printf("%d \n", *(int *)lst_a->content);
			lst_a = lst_a->next;
			size_a--;
		}
		else if (size_a < size_b)
		{
			ft_printf("  %d\n", *(int *)lst_b->content);
			lst_b = lst_b->next;
			size_b--;
		}
		else
		{
			ft_printf("%d %d\n", *(int *)lst_a->content, *(int *)lst_b->content);
			lst_a = lst_a->next;
			lst_b = lst_b->next;
			size_a--;
			size_b--;
		}
	}
	ft_printf("_ _\na b\n\n");
}

int	main(int argc, char **argv)
{
	int		i;
	int		*nb;
	t_list	*lst_a = NULL;
	t_list	*lst_b = NULL;
	t_list	*elem;

	i = 1;
	while (i < argc)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(argv[i]);
		elem = ft_lstnew(nb);
		ft_lstadd_front(&lst_a, elem);
		ft_printf("[%s] ", argv[i]);
		i++;
	}
	visualize(lst_a, lst_b);
	ft_printf("sa :\n");
	swap_elem(&lst_a);
	visualize(lst_a, lst_b);
	ft_printf("pb pb pb :\n");
	push_elem(&lst_b, &lst_a);
	push_elem(&lst_b, &lst_a);
	push_elem(&lst_b, &lst_a);
	visualize(lst_a, lst_b);
	ft_printf("ra rb :\n");
	rotate_elem(&lst_a);
	rotate_elem(&lst_b);
	visualize(lst_a, lst_b);
	ft_printf("rra rrb :\n");
	reverse_rotate_elem(&lst_a);
	reverse_rotate_elem(&lst_b);
	visualize(lst_a, lst_b);

	ft_lstclear(&lst_a, &free);
	ft_lstclear(&lst_b, &free);
	return (0);
}
