/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:57:55 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/13 10:01:58 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>

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
