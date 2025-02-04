/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:49:58 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/04 17:23:23 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/gnl/get_next_line_bonus.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		input_valid;

	a = NULL;
	b = NULL;
	input_valid = collect_input(argc, argv, &a);
	if (!input_valid)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	execute(&a, &b);
	if (sorted(&a) && stack_len(&b) == 0)
	{
		ft_putendl_fd("OK", STDOUT_FILENO);
		return (clear_stack(&a), clear_stack(&b), EXIT_SUCCESS);
	}
	ft_putendl_fd("KO", STDOUT_FILENO);
	return (clear_stack(&a), clear_stack(&b), EXIT_FAILURE);
}
