/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_mem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 15:55:43 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/10 15:57:17 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	*stack = NULL;
}

void	clear_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
