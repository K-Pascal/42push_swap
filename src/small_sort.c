/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:44:30 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 14:50:31 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "inc/actions.h"
#include "inc/sorts_utils.h"

static t_actions	get_sort_instructions(int val1, int val2, int val3)
{
	t_actions	actions;

	actions = 0;
	if (val1 < val2 && val1 < val3)
	{
		if (val2 > val3)
			actions |= SWAP | ROTATE | REVERSE_ROTATE;
	}
	else if (val2 < val1 && val2 < val3)
	{
		if (val3 > val1)
			actions |= SWAP;
		else
			actions |= ROTATE;
	}
	else
	{
		if (val1 > val2)
			actions |= SWAP;
		actions |= REVERSE_ROTATE;
	}
	return (actions);
}

static t_actions	sort_2_values(t_list *stack)
{
	if (*(int *)stack->content > *(int *)stack->next->content)
		return (SWAP);
	return (0);
}

static t_actions	sort_3_values(t_list *stack)
{
	int	val1;
	int	val2;
	int	val3;
	int	size;

	size = ft_lstsize(stack);
	if (size < 2 || size > 3)
		return (0);
	if (size == 2)
		return (sort_2_values(stack));
	val1 = *(int *)stack->content;
	val2 = *(int *)stack->next->content;
	val3 = *(int *)stack->next->next->content;
	return (get_sort_instructions(val1, val2, val3));
}

void	sort_6_values(t_list **stack_a, int size_a)
{
	t_list		*stack_b;
	t_actions	act_a;
	t_actions	act_b;

	stack_b = NULL;
	act_b = 0;
	while (size_a > 3)
	{
		set_command(stack_a, &stack_b, "pb", 2);
		size_a--;
	}
	act_a = sort_3_values(*stack_a);
	act_b = sort_3_values(stack_b);
	do_actions(stack_a, &stack_b, act_a, act_b);
	size_a = ft_lstsize(*stack_a);
	push_values(stack_a, &stack_b, size_a);
	goto_minvalue(stack_a);
}
