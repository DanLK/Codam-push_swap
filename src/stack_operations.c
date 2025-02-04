/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:03:52 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/04 11:19:33 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap top elements */
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack))
		return ;
	first = *stack;
	if (!(first->next))
		return ;
	second = first->next;
	first->next = second->next;
	if ((second->next))
		(second->next)->prev = first;
	second->next = first;
	*stack = second;
	second->index--;
	first->index++;
	second->prev = NULL;
	first->prev = second;
	update_median(stack);
}

/* Put the first element from the top of b at the top of a 
PUSH A */
void	push(t_stack **a, t_stack **b, char na)
{
	t_stack	*first_b;
	t_stack	*first_b_copy;

	if (!a || !b || !*b)
		return ;
	first_b = *b;
	first_b_copy = ft_stack_new(first_b->num, na);
	if (!first_b_copy)
		return ;
	if (!*a)
		ft_stack_add_back(a, first_b_copy);
	else
	{
		first_b_copy->next = *a;
		(*a)->prev = first_b_copy;
	}
	if (first_b->next)
		(first_b->next)->prev = NULL;
	if (*a)
		*a = first_b_copy;
	*b = first_b->next;
	update_stack(a);
	update_stack(b);
	free(first_b);
}

/* First element becomes last */
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	last = ft_stack_last(*stack);
	second->prev = NULL;
	*stack = second;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	update_stack(stack);
}

/* Last element becomes first */
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*st_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_stack_last(*stack);
	st_last = *stack;
	while (st_last->next != last)
		st_last = st_last->next;
	st_last->next = NULL;
	(*stack)->prev = last;
	last->next = *stack;
	*stack = last;
	last->prev = NULL;
	update_stack(stack);
}
