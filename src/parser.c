/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:11:02 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/13 09:35:19 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "stack.h"

static int	isvalidnumber(char str[]);
static int	checkmaxint(char delim[], size_t lenmax, char str[]);
static int	isvalidint(char str[]);
static int	*checkduplicate(t_list *stack, char arg[]);

t_list	*checkargs(char **argv, int size)
{
	t_list	*stack;
	int		*nbr;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		if (!isvalidnumber(argv[i]) || !isvalidint(argv[i]))
		{
			ft_putendl_fd("Error", 2);
			ft_lstclear(&stack, &free);
			return (NULL);
		}
		nbr = checkduplicate(stack, argv[i]);
		if (!nbr)
			return (NULL);
		if (!addto_stack(&stack, nbr))
			return (NULL);
		i++;
	}
	return (stack);
}

static int	isvalidnumber(char str[])
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	return (*str == '\0');
}

static int	isvalidint(char str[])
{
	char	sign;
	char	*delim;
	int		status;

	sign = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
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

static int	*checkduplicate(t_list *stack, char arg[])
{
	int		nbr;
	int		*narg;

	nbr = ft_atoi(arg);
	while (stack)
	{
		if (nbr == *(int *)stack->content)
		{
			ft_lstclear(&stack, &free);
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		stack = stack->next;
	}
	narg = malloc(sizeof(int));
	if (!narg)
	{
		ft_lstclear(&stack, &free);
		ft_putendl_fd("Allocation error in checkduplicate() : int*", 2);
		return (NULL);
	}
	*narg = nbr;
	return (narg);
}

static int	checkmaxint(char delim[], size_t lenmax, char str[])
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
