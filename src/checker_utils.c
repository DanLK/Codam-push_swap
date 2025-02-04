/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/31 13:48:43 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/04 11:23:42 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/gnl/get_next_line_bonus.h"
#include <unistd.h>

void	execute(t_stack **a, t_stack **b)
{
	char	*op;
	int		valid_exec;

	if (!a || !b)
		return ;
	op = get_next_line(STDIN_FILENO);
	while (op && op[0] != '\n')
	{
		valid_exec = execute_one(a, b, op);
		free(op);
		if (valid_exec != 1)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		op = get_next_line(STDIN_FILENO);
	}
	free(op);
}

int	execute_one(t_stack **a, t_stack **b, char *op)
{
	if (!a || !b || !op)
		return (-1);
	if (op[0] == 's')
	{
		if (op[1] == 'a')
			return (swap(a), 1);
		else if (op[1] == 'b')
			return (swap(b), 1);
		else if (op[1] == 's')
			return (ss(a, b), 1);
	}
	if (op[0] == 'p')
	{
		if (op[1] == 'a')
			return (push(a, b, 'a'), 1);
		else if (op[1] == 'b')
			return (push(b, a, 'b'), 1);
	}
	if (op[0] == 'r')
		return (execute_rotate(a, b, op));
	return (0);
}

int	execute_rotate(t_stack **a, t_stack **b, char *op)
{
	if (!a || !b || !op)
		return (-1);
	if (op[1] == 'a')
		return (rotate(a), 1);
	if (op[1] == 'b')
		return (rotate(b), 1);
	if (op[1] == 'r')
	{
		if (op[2] == '\n')
			return (rr(a, b), 1);
		else if (op[2] == 'a')
			return (reverse_rotate(a), 1);
		else if (op[2] == 'b')
			return (reverse_rotate(b), 1);
		else if (op[2] == 'r')
			return (rrr(a, b), 1);
	}
	return (0);
}
