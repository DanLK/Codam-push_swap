/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 12:48:10 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/27 13:53:02 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->index = 0;
		return ;
	}
	last = ft_stack_last(*stack);
	last->next = new;
	new->prev = last;
	new->index = last->index + 1;
	update_median(stack);
}

void	ft_stack_addb_by_num(t_stack **stack, int num, char name)
{
	t_stack	*new;

	if (!stack)
		return ;
	new = ft_stack_new(num, name);
	ft_stack_add_back(stack, new);
}

t_stack	*get_node(t_stack **stack, int index)
{
	t_stack	*node;

	if (!stack)
		return (NULL);
	node = *stack;
	while (index > 0 && node)
	{
		node = node->next;
		index--;
	}
	return (node);
}
