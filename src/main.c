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

int	findmin(t_list *lst)
{
	int	min;
	int	i;
	int	index;

	min = INT_MAX;
	i = 0;
	index = i;
	while (lst)
	{
		if (*(int *)lst->content <= min)
		{
			min = *(int *)lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}

int	findmax(t_list *lst)
{
	int	max;
	int	i;
	int	index;

	max = INT_MIN;
	i = 0;
	index = i;
	while (lst)
	{
		if (*(int *)lst->content >= max)
		{
			max = *(int *)lst->content;
			index = i;
		}
		lst = lst->next;
		i++;
	}
	return (index);
}

int	isascending(t_list *lst)
{
	int	nbr;

	if (!lst || !lst->next)
		return (1);
	while (lst->next)
	{
		nbr = *(int *)lst->content;
		if (nbr > *(int *)lst->next->content)
			nbr = *(int *)lst->next->content;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
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
