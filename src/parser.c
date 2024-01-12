/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:11:02 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/08 16:37:17 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

#include "libft/libft.h"

static int	isvalidnumber(char str[]);
static int	checkmaxint(char delim[], size_t lenmax, char str[]);
static int	isvalidint(char str[]);
static int	checkduplicate(char **argv, int start, int index);

int	checkargs(char **argv, int start, int size)
{
	int	i;

	i = start;
	while (i < size)
	{
		if (!isvalidnumber(argv[i])
			|| !isvalidint(argv[i])
			|| checkduplicate(argv, start, i))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	isvalidnumber(char str[])
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}

static int	isvalidint(char str[])
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

static int	checkduplicate(char **argv, int start, int index)
{
	int	i;
	int	nbr;

	i = start;
	nbr = ft_atoi(argv[index]);
	while (i < index)
	{
		if (ft_atoi(argv[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
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
