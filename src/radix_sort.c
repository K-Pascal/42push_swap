/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:47:41 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 17:24:05 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

#include "inc/actions.h"
#include "inc/sorts_utils.h"

static int	cheapest_goto(t_list **stack_a, int index, int size_a);
static void	push_numbers(t_list **stack_a, t_list **stack_b, int size_a);

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
		size_a = cheapest_goto(stack_a, index, size_a);
		push_numbers(stack_a, &stack_b, size_a);
		max >>= 1;
	}
	ft_lstclear(&stack_b, &free);
}

static void	bitshiftprevious(t_list *stack_a, int step, int size)
{
	while (step--)
		stack_a = stack_a->next;
	while (size--)
	{
		if (*(int *)stack_a->content & 1)
			bitshiftvalue(stack_a->content);
		stack_a = stack_a->next;
	}
}

static int	cheapest_goto(t_list **stack_a, int index, int size_a)
{
	int		step;

	step = 0;
	if (index <= size_a / 2)
	{
		while (index--)
		{
			bitshiftvalue((*stack_a)->content);
			set_command(stack_a, NULL, "ra", 2);
			step++;
		}
		size_a -= step;
	}
	else
	{
		while (index++ < size_a)
		{
			set_command(stack_a, NULL, "rra", 3);
			step++;
		}
		bitshiftprevious(*stack_a, step, size_a - step);
		size_a = step;
	}
	return (size_a);
}

static void	push_numbers(t_list **stack_a, t_list **stack_b, int size_a)
{
	while (size_a--)
	{
		if (!(*(int *)(*stack_a)->content & 1))
		{
			bitshiftvalue((*stack_a)->content);
			set_command(stack_a, stack_b, "pb", 2);
		}
		else
		{
			bitshiftvalue((*stack_a)->content);
			set_command(stack_a, NULL, "ra", 2);
		}
	}
	while (*stack_b)
		set_command(stack_a, stack_b, "pa", 2);
}
