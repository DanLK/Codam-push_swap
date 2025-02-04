/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 14:42:22 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/31 15:09:48 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int num, char name)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->name = name;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = false;
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	return (new);
}

int	stack_len(t_stack **stack)
{
	int		len;
	t_stack	*node;

	len = 0;
	if (!stack)
		return (-1);
	node = *stack;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

void	update_median(t_stack **stack)
{
	t_stack	*node;
	int		median;
	int		len;

	if (!stack)
		return ;
	len = stack_len(stack);
	median = len / 2;
	if (len % 2 != 0)
		median++;
	node = *stack;
	while (node)
	{
		if (node->index < median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
	}
}

void	update_indices(t_stack **stack)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	if (node)
	{
		node->index = 0;
		node = node->next;
	}
	while (node)
	{
		node->index = (node->prev)->index + 1;
		node = node->next;
	}
}

void	update_stack(t_stack **stack)
{
	update_indices(stack);
	update_median(stack);
}
