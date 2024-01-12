/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/05 14:24:26 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "inc/actions.h"
#include <stdlib.h>

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
	if (argc == 2)
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
