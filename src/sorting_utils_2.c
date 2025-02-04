/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_utils_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 13:58:55 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/28 16:40:42 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Brings a node to the top of the stack*/
void	to_top(t_stack *node, t_stack **stack, char name)
{
	int	rotations;

	if (!stack || !node || node->index == 0)
		return ;
	if (node->above_median)
	{
		rotations = node->index;
		while (rotations > 0)
		{
			rotate(stack);
			ft_printf("r%c\n", name);
			rotations--;
		}
	}
	else
	{
		rotations = stack_len(stack) - node->index;
		while (rotations > 0)
		{
			reverse_rotate(stack);
			ft_printf("rr%c\n", name);
			rotations--;
		}
	}
	update_stack(stack);
}

/* Rotates both stacks together assuming the first node is closer*/
void	both_to_top(t_stack *n_a, t_stack *n_b, t_stack **a, t_stack **b)
{
	int	rotations;

	if (!n_a || !n_b || !a || !b)
		return ;
	if (n_a->above_median)
	{
		rotations = n_a->index;
		while (rotations > 0)
		{
			rr(a, b);
			ft_printf("rr\n");
			rotations--;
		}
	}
	else
	{
		rotations = stack_len(a) - n_a->index;
		while (rotations-- > 0)
		{
			rrr(a, b);
			ft_printf("rrr\n");
		}
	}
	update_stack(a);
	update_stack(b);
}

void	push_cheapest(t_stack *node, t_stack **a, t_stack **b)
{
	if (!node || !a || !b || !node->target)
		return ;
	if (node->above_median && (node->target)->above_median)
		move_both_up(node, a, b);
	if (!node->above_median && !(node->target)->above_median)
		move_both_down(node, a, b);
	else
	{
		to_top(node, a, (*a)->name);
		to_top(node->target, b, (*b)->name);
	}
	push(b, a, (*b)->name);
	ft_printf("p%c\n", (*b)->name);
}

/* Assuming both node and target are above median*/
void	move_both_up(t_stack *node, t_stack **a, t_stack **b)
{
	int	ops_node;
	int	ops_target;

	ops_node = node->index;
	ops_target = (node->target)->index;
	if (ops_node >= ops_target)
	{
		both_to_top((node->target), node, b, a);
		to_top(node, a, (*a)->name);
	}
	else
	{
		both_to_top(node, node->target, a, b);
		to_top(node->target, b, (*b)->name);
	}
}

/* Assuming both node and target are below the median*/
void	move_both_down(t_stack *node, t_stack **a, t_stack **b)
{
	int	ops_node;
	int	ops_target;

	ops_node = stack_len(a) - node->index;
	ops_target = stack_len(b) - (node->target)->index;
	if (ops_node >= ops_target)
	{
		both_to_top((node->target), node, b, a);
		to_top(node, a, (*a)->name);
	}
	else
	{
		both_to_top(node, node->target, a, b);
		to_top(node->target, b, (*b)->name);
	}
}
