/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/08 17:11:51 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <limits.h>

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "inc/actions.h"

void	my_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

//void	my_selection_sort(t_list **stack_a, int size_a)
//{
//	t_list	*stack_b;
//	t_info	min;
//
//	stack_b = NULL;
//	while (*stack_a)
//	{
//		min = findmin(*stack_a);
//		if (min.index <= size_a / 2)
//		{
//			while (min.index-- > 0)
//				set_command(stack_a, &stack_b, "ra");
//		}
//		else
//		{
//			while (min.index++ < size_a)
//				set_command(stack_a, &stack_b, "rra");
//		}
//		size_a--;
//		set_command(stack_a, &stack_b, "pb");
//	}
//	while (stack_b)
//		set_command(stack_a, &stack_b, "pa");
//	ft_lstclear(&stack_b, &free);
//}

void	init_ints(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = -1;
		i++;
	}
}

void	set_ranks(int *pos, int size, t_list *stack)
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

int	dothing(char **argv, int size)
{
	t_list	*stack_a;

	stack_a = checkargs(argv, size);
	pre_sort(stack_a, size);
	if (!stack_a)
		return (0);
	my_radix_sort(&stack_a, size);
	ft_lstclear(&stack_a, &free);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		argc = 0;
		while (argv[argc] != NULL)
			argc++;
		dothing(argv, argc);
		my_free_all(argv);
	}
	else
		dothing(&argv[1], argc - 1);
	return (0);
}
