/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:48:16 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/21 14:09:11 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

int	addto_stack(t_list **stack, void *content)
{
	t_list	*elem;

	elem = ft_lstnew(content);
	if (!elem)
	{
		ft_lstclear(stack, &free);
		free(content);
		ft_putendl_fd("Allocation error in addto_stack() : t_list*", 2);
		return (0);
	}
	ft_lstadd_back(stack, elem);
	return (1);
}
