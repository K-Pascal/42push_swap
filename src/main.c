/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:44 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 15:01:15 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

#include "inc/actions.h"
#include "inc/parser.h"
#include "inc/ranks.h"
#include "inc/sorts.h"

void	my_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

int	sort_values(char **argv, int size)
{
	t_list	*stack_a;

	stack_a = checkargs(argv, size);
	pre_sort(stack_a, size);
	if (!stack_a)
		return (0);
	if (size > 1)
	{
		if (size <= 6)
			sort_6_values(&stack_a, size);
		else
			my_radix_sort(&stack_a, size);
	}
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
		sort_values(argv, argc);
		my_free_all(argv);
	}
	else
		sort_values(&argv[1], argc - 1);
	return (0);
}
