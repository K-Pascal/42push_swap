/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:55:54 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 15:00:15 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

#include "libft/libft.h"

static void	init_ints(int *arr, int size);
static void	set_ranks(int *pos, int size, t_list *stack);

void	pre_sort(t_list *stack, int size)
{
	int		*pos;
	int		i;

	pos = malloc(size * sizeof(int));
	if (!pos)
	{
		ft_putendl_fd("Allocation error in pre_sort() : int*", 2);
		return ;
	}
	init_ints(pos, size);
	set_ranks(pos, size, stack);
	i = 0;
	while (stack)
	{
		*(int *)stack->content = pos[i++];
		stack = stack->next;
	}
	free(pos);
}

static void	init_ints(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = -1;
		i++;
	}
}

static void	set_ranks(int *pos, int size, t_list *stack)
{
	int		rank;
	int		min;
	int		i;
	int		index;
	t_list	*elem;

	rank = 0;
	while (size--)
	{
		i = 0;
		index = 0;
		min = INT_MAX;
		elem = stack;
		while (elem)
		{
			if (pos[i] == -1 && *(int *)elem->content <= min)
			{
				min = *(int *)elem->content;
				index = i;
			}
			i++;
			elem = elem->next;
		}
		pos[index] = rank++;
	}
}
