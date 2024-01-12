/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/03 22:13:06 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdlib.h>

void	swap_elem(t_list **lst)
{
	t_list	*first;

	if (ft_lstsize(*lst) <= 1)
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

	if (ft_lstsize(*lst) <= 1)
		return ;
	first = (*lst)->next;
	last = *lst;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = last;
	last->next = NULL;
	*lst = first;
}

void	print_elem(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*nb;
	t_list	*lst_a;
	t_list	*lst_b;

	i = 1;
	while (i < argc)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(argv[i]);
		ft_lstadd_front(&lst_a, ft_lstnew(nb));
		i++;
	}
	ft_lstiter(lst_a, &print_elem);
	ft_printf("sa :\n");
	swap_elem(&lst_a);
	ft_lstiter(lst_a, &print_elem);
	ft_printf("\npb pb pb :\n");
	push_elem(&lst_b, &lst_a);
	push_elem(&lst_b, &lst_a);
	push_elem(&lst_b, &lst_a);
	ft_lstiter(lst_a, &print_elem);
	ft_printf("\n");
	ft_lstiter(lst_b, &print_elem);
	ft_printf("\nra rb :\n");
	rotate_elem(&lst_a);
	rotate_elem(&lst_b);
	ft_lstiter(lst_a, &print_elem);
	ft_printf("\n");
	ft_lstiter(lst_b, &print_elem);
	ft_printf("\n");
	ft_lstclear(&lst_a, &free);
	ft_lstclear(&lst_b, &free);
	return (0);
}
