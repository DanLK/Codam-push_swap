/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cost_analysis.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 12:54:31 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/31 15:08:23 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_smaller_stack(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = *a;
	while (node)
	{
		set_target_smaller_node(node, b);
		node = node->next;
	}
}

void	set_push_cost(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = *a;
	while (node)
	{
		node->push_cost = calc_pushcost_node(node, a, b);
		node = node->next;
	}
}

t_stack	*find_cheapest(t_stack **stack)
{
	int		min_cost;
	int		index;
	t_stack	*node;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	min_cost = node->push_cost;
	index = node->index;
	while (node)
	{
		if (node->push_cost < min_cost)
		{
			min_cost = node->push_cost;
			index = node->index;
		}
		node = node->next;
	}
	return (get_node(stack, index));
}
