/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 18:55:19 by dloustalot    #+#    #+#                 */
/*   Updated: 2025/03/10 14:08:35 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pretty_print_stack(t_stack **stack)
{
	t_stack	*node;

	if (!stack)
	{
		ft_printf("Nothing to print\n");
		return ;
	}
	node = *stack;
	if (!node)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	while (node)
	{
		ft_printf("%d\n", node->num);
		node = node->next;
	}
	ft_printf("-----\n");
	ft_printf("  %c  \n", (*stack)->name);
}

void	verbose_print_node(t_stack *node)
{
	if (!node)
		return ;
	ft_printf("-------\n");
	ft_printf("Num: %d\n", node->num);
	ft_printf("Name: %c\n", node->name);
	ft_printf("Index: %d\n", node->index);
	ft_printf("Push cost: %d\n", node->push_cost);
	ft_printf("Above median: %d\n", (int)node->above_median);
	if (node->prev == NULL)
		ft_printf("Prev: -\n");
	else
		ft_printf("Prev: %d\n", (node->prev)->num);
	if (node->next == NULL)
		ft_printf("Next: -\n");
	else
		ft_printf("Next: %d\n", (node->next)->num);
	if (node->target == NULL)
		ft_printf("Target: -\n");
	else
		ft_printf("Target: %d\n", (node->target)->num);
	ft_printf("-------\n");
}

void	verbose_print_stack(t_stack **stack)
{
	t_stack	*node;

	if (!stack)
	{
		ft_printf("Nothing to print\n");
	}
	node = *stack;
	if (!node)
		ft_printf("Stack is empty\n");
	while (node)
	{
		verbose_print_node(node);
		node = node->next;
	}
}
