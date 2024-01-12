/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:25 by pnguyen-          #+#    #+#             */
/*   Updated: 2023/12/14 14:53:05 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "inc/actions.h"
#include "inc/sorts_utils.h"

static void	do_rotate(t_list **s_a, t_list **s_b, t_actions a, t_actions b);
static void	do_swap(t_list **s_a, t_list **s_b, t_actions a, t_actions b);
static void	do_rrotate(t_list **s_a, t_list **s_b, t_actions a, t_actions b);

void	do_actions(t_list **s_a, t_list **s_b, t_actions a_a, t_actions a_b)
{
	if (a_a & ROTATE || a_b & ROTATE)
		do_rotate(s_a, s_b, a_a, a_b);
	if (a_a & SWAP || a_b & SWAP)
		do_swap(s_a, s_b, a_a, a_b);
	if (a_a & REVERSE_ROTATE || a_b & REVERSE_ROTATE)
		do_rrotate(s_a, s_b, a_a, a_b);
}

static void	do_rotate(t_list **s_a, t_list **s_b, t_actions a_a, t_actions a_b)
{
	if (a_a & ROTATE && a_b & ROTATE)
		set_command(s_a, s_b, "rr", 2);
	else
	{
		if (a_a & ROTATE)
			set_command(s_a, s_b, "ra", 2);
		if (a_b & ROTATE)
			set_command(s_a, s_b, "rb", 2);
	}
}

static void	do_swap(t_list **s_a, t_list **s_b, t_actions a_a, t_actions a_b)
{
	if (a_a & SWAP && a_b & SWAP)
		set_command(s_a, s_b, "ss", 2);
	else
	{
		if (a_a & SWAP)
			set_command(s_a, s_b, "sa", 2);
		if (a_b & SWAP)
			set_command(s_a, s_b, "sb", 2);
	}
}

static void	do_rrotate(t_list **s_a, t_list **s_b, t_actions a_a, t_actions a_b)
{
	if (a_a & REVERSE_ROTATE && a_b & REVERSE_ROTATE)
		set_command(s_a, s_b, "rrr", 3);
	else
	{
		if (a_a & REVERSE_ROTATE)
			set_command(s_a, s_b, "rra", 3);
		if (a_b & REVERSE_ROTATE)
			set_command(s_a, s_b, "rrb", 3);
	}
}
