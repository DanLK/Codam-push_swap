/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_handles.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/13 10:27:15 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/31 16:06:30 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reads the input and determines whether it's valid
while filling up stack a if necessary */
int	collect_input(int argc, char **argv, t_stack **stack)
{
	int	valid_numbers;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		valid_numbers = check_string(argv[1], stack);
	else
		valid_numbers = check_numbers(argc - 1, argv, stack);
	if (valid_numbers)
		return (1);
	else
		return (0);
}

int	sorted(t_stack **stack)
{
	t_stack	*node;
	int		value;

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
			return (0);
		value = node ->num;
		node = node->next;
	}
	return (1);
}
