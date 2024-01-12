/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:57:55 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 17:16:15 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>

#include "libft/libft.h"
#include "inc/actions.h"

int	findmax(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (*(int *)stack->content >= max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

void	push_values(t_list **stack_a, t_list **stack_b, int size_a)
{
	while (*stack_b)
	{
		while (size_a--)
		{
			if (*(int *)(*stack_b)->content < *(int *)(*stack_a)->content)
				break ;
			else
				set_command(stack_a, stack_b, "ra", 2);
		}
		size_a += 2;
		set_command(stack_a, stack_b, "pa", 2);
	}
}

void	goto_minvalue(t_list **stack_a)
{
	t_list	*stack_temp;
	int		index;
	int		size_a;

	index = 0;
	stack_temp = *stack_a;
	while (stack_temp)
	{
		if (*(int *)stack_temp->content == 0)
			break ;
		index++;
		stack_temp = stack_temp->next;
	}
	size_a = ft_lstsize(*stack_a);
	if (index <= size_a / 2)
	{
		while (index--)
			set_command(stack_a, NULL, "ra", 2);
	}
	else
	{
		while (index++ < size_a)
			set_command(stack_a, NULL, "rra", 3);
	}
}

int	findzero(t_list *stack)
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

void	bitshiftvalue(void *content)
{
	*(int *)content >>= 1;
}
