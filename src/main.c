/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/07 17:36:52 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "inc/actions.h"

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

void	my_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

int	isvalidnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}

int	checkmaxint(char delim[], size_t lenmax, char str[])
{
	size_t	len;

	len = ft_strlen(str);
	if (len > lenmax)
		return (0);
	if (len == lenmax)
	{
		while (*delim != '\0')
		{
			if (*str > *delim)
				return (0);
			if (*str != *delim)
				return (1);
			str++;
			delim++;
		}
	}
	return (1);
}

int	isvalidint(char *str)
{
	char	sign;
	char	*delim;
	int		status;

	sign = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (1);
	if (sign == 0)
		delim = ft_itoa(INT_MAX);
	else
		delim = ft_itoa(INT_MIN);
	status = checkmaxint(delim + sign, ft_strlen(delim) - sign, str);
	free(delim);
	return (status);
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

t_list	*dothing(char **argv, int i, int size)
{
	t_list	*lst_a;
	int		*nb;

	lst_a = NULL;
	while (i < size)
	{
		if (!isvalidnumber(argv[i]) || !isvalidint(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(argv[i]);
		if (!nb)
		{
			ft_lstclear(&lst_a, &free);
			return (NULL);
		}
		ft_lstadd_front(&lst_a, ft_lstnew(nb));
		i++;
	}
	visualize(lst_a, NULL);
	ft_printf("max : %d\n", findmax(lst_a));
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
