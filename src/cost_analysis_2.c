/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cost_analysis_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 13:56:00 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/30 12:17:28 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sets as target for node, the closest smaller node from stack OR the max */
void	set_target_smaller_node(t_stack *node, t_stack **stack)
{
	t_stack	*target;
	t_stack	*temp;
	int		targ_value;

	if (!stack || !node || !(*stack))
		return ;
	temp = *stack;
	target = *stack;
	targ_value = node->num;
	while (temp)
	{
		if (temp->num < node->num
			&& (targ_value == node->num || temp->num > targ_value))
		{
			target = temp;
			targ_value = target->num;
		}
		temp = temp->next;
	}
	if (targ_value == node->num)
		node->target = get_node(stack, get_max(stack));
	else
		node->target = target;
}

/* Sets as target for node the closest bigger node from stack OR the min */
void	set_target_bigger_node(t_stack *node, t_stack **stack)
{
	t_stack	*target;
	t_stack	*temp;
	int		targ_value;

	if (!stack || !node || !(*stack))
		return ;
	temp = *stack;
	target = *stack;
	targ_value = node->num;
	while (temp)
	{
		if (temp->num > node->num
			&& (targ_value == node->num || temp->num < targ_value))
		{
			target = temp;
			targ_value = target->num;
		}
		temp = temp->next;
	}
	if (targ_value == node->num)
		node->target = get_node(stack, get_min(stack));
	else
		node->target = target;
}

/* Calculates the cost of pushing node from stack a to stack b*/
int	calc_pushcost_node(t_stack *node, t_stack **a, t_stack **b)
{
	int	above_med;
	int	above_med_target;

	if (!node || !a || !b)
		return (-1);
	above_med = node->above_median;
	above_med_target = (node->target)->above_median;
	if (above_med)
	{
		if (above_med_target)
		{
			if (node->index >= (node->target)->index)
				return (node->index);
			return ((node->target)->index);
		}
		return (node->index + stack_len(b) - (node->target)->index);
	}
	if (!above_med_target)
	{
		if (stack_len(a) - node->index >= stack_len(b) - (node->target)->index)
			return (stack_len(a) - node->index);
		return (stack_len(b) - (node->target)->index);
	}
	return (stack_len(a) - node->index + (node->target)->index);
}
