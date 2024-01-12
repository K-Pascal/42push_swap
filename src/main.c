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

t_list	*dothing(char **argv, int start, int size)
{
	t_list	*lst_a;
	int		*nb;
	int		i;

	lst_a = NULL;
	i = start;
	if (!checkargs(argv, start, size))
		return (NULL);
	while (i < size)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(argv[i]);
		if (!nb)
		{
			ft_lstclear(&lst_a, &free);
			return (NULL);
		}
		ft_lstadd_back(&lst_a, ft_lstnew(nb));
		i++;
	}
	int	imin;
	int	lst_size = ft_lstsize(lst_a);
	t_list	*lst_b = NULL;
	int	half = lst_size / 2;
	while (lst_size > 0)
	{
		if (*(int *)lst_a->content > *(int *)lst_a->next->content)
			set_command(&lst_a, &lst_b, "sa");
		else
		{
			imin = findmin(lst_a);
			if (imin <= half)
			{
				while (imin--)
					set_command(&lst_a, &lst_b, "ra");
			}
			else
			{
				while (imin++ < lst_size)
					set_command(&lst_a, &lst_b, "rra");
			}
			set_command(&lst_a, &lst_b, "pb");
			lst_size--;
		}
		if (isascending(lst_a))
			break ;
	}
	while (lst_b)
		set_command(&lst_a, &lst_b, "pa");
	ft_lstclear(&lst_a, &free);
	ft_lstclear(&lst_b, &free);
	return (lst_a);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	i = argc != 2;
	if (!i)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		argc = 0;
		while (argv[argc] != NULL)
			argc++;
	}
	dothing(argv, i, argc);
	if (!i)
		my_free_all(argv);
	return (0);
}
