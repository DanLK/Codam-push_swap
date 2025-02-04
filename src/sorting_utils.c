/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 21:30:52 by dloustalot    #+#    #+#                 */
/*   Updated: 2025/02/04 11:31:38 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the index of the MAX node */
int	get_max(t_stack **stack)
{
	t_stack	*node;
	int		max;
	int		i;

	if (!stack || !*stack)
		return (-1);
	node = *stack;
	max = node->num;
	i = node->index;
	while (node)
	{
		if (node->num > max)
		{
			max = node->num;
			i = node->index;
		}
		node = node->next;
	}
	return (i);
}

int	get_min(t_stack **stack)
{
	t_stack	*node;
	int		min;
	int		i;

	if (!stack || !*stack)
		return (-1);
	node = *stack;
	min = node->num;
	i = node->index;
	while (node)
	{
		if (node->num < min)
		{
			min = node->num;
			i = node->index;
		}
		node = node->next;
	}
	return (i);
}

/* Sorts a stack with two or less elements in ascending order */
void	sort_two(t_stack **stack)
{
	if (!stack)
		return ;
	if (stack_len(stack) == 1)
		return ;
	if ((*stack)->num > ((*stack)->next)->num)
	{
		swap(stack);
		ft_printf("s%c\n", (*stack)->name);
	}
}

/* Sorts a stack with three elements in ascending order */
void	sort_three(t_stack **stack)
{
	int	i_max;

	if (!stack)
		return ;
	i_max = get_max(stack);
	if (i_max == 0)
	{
		rotate(stack);
		ft_printf("r%c\n", (*stack)->name);
	}
	if (i_max == 1)
	{
		reverse_rotate(stack);
		ft_printf("rr%c\n", (*stack)->name);
	}
	sort_two(stack);
}

int	circularly_sorted(t_stack **stack)
{
	int		value;
	t_stack	*node;

	if (!stack || !*stack)
		return (-1);
	if (stack_len(stack) == 1)
		return (1);
	node = *stack;
	value = node->num;
	node = node->next;
	while (node)
	{
		if (node->num < value)
		{
			if ((node->prev)->index != get_max(stack)
				|| node->index != get_min(stack))
				return (0);
		}
		value = node->num;
		node = node->next;
	}
	if ((*stack)->num < ft_stack_last(*stack)->num
		&& get_max(stack) != stack_len(stack) - 1)
		return (0);
	return (1);
}
