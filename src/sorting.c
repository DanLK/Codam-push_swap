/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 11:12:35 by dloustal      #+#    #+#                 */
/*   Updated: 2025/03/10 14:38:56 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	if (circularly_sorted(a))
		return (shift(a));
	push(b, a, 'b');
	ft_printf("pb\n");
	if (stack_len(a) > 3)
	{
		push(b, a, 'b');
		ft_printf("pb\n");
	}
	push_to_aux_stack(a, b);
	if (stack_len(a) == 3)
		sort_three(a);
	else
		shift(a);
	shift_desc(b);
	return_sorted(a, b);
	shift(a);
}

/* Assuming that the stack is circularly sorted, it brings the min to the top*/
void	shift(t_stack **stack)
{
	int		index_min;
	t_stack	*min_node;

	index_min = get_min(stack);
	min_node = get_node(stack, index_min);
	to_top(min_node, stack, min_node->name);
}

void	return_sorted(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	while (stack_len(b) > 0)
	{
		set_target_bigger_node(*b, a);
		push_cheapest(*b, b, a);
	}
}

void	push_to_aux_stack(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!a || !b)
		return ;
	while (stack_len(a) > 3)
	{
		if (circularly_sorted(a))
			break ;
		set_target_smaller_stack(a, b);
		set_push_cost(a, b);
		node = find_cheapest(a);
		push_cheapest(node, a, b);
	}
}

/* Assuming the stack is circularly sorted in descending order, put MAX on top*/
void	shift_desc(t_stack **stack)
{
	int		index_max;
	t_stack	*max_node;

	index_max = get_max(stack);
	max_node = get_node(stack, index_max);
	to_top(max_node, stack, max_node->name);
}
