/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:47:41 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/13 10:00:43 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

#include "inc/actions.h"
#include "inc/sorts_utils.h"

static int	findzero(t_list *stack)
{
	int		index;

	index = 0;
	while (stack)
	{
		if (!(*(int *)stack->content & 1))
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

static void	bitshiftvalue(void *content)
{
	*(int *)content >>= 1;
}

void	my_radix_sort(t_list **stack_a, int size_a)
{
	t_list	*stack_b;
	int		index;
	int		max;

	stack_b = NULL;
	max = findmax(*stack_a);
	while (max)
	{
		size_a = ft_lstsize(*stack_a);
		index = findzero(*stack_a);
		if (index == -1)
		{
			max >>= 1;
			ft_lstiter(*stack_a, &bitshiftvalue);
			continue ;
		}
		if (index <= size_a / 2)
		{
			while (index--)
			{
				bitshiftvalue((*stack_a)->content);
				set_command(stack_a, &stack_b, "ra");
				size_a--;
			}
		}
		else
		{
			while (index < size_a)
			{
				bitshiftvalue((*stack_a)->content);
				set_command(stack_a, &stack_b, "rra");
				size_a--;
			}
		}
		while (size_a--)
		{
			if (!(*(int *)(*stack_a)->content & 1))
			{
				bitshiftvalue((*stack_a)->content);
				set_command(stack_a, &stack_b, "pb");
			}
			else
			{
				bitshiftvalue((*stack_a)->content);
				set_command(stack_a, &stack_b, "ra");
			}
		}
		while (stack_b)
			set_command(stack_a, &stack_b, "pa");
		max >>= 1;
	}
	ft_lstclear(&stack_b, &free);
}
