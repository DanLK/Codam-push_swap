/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 16:22:23 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/04 17:39:46 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		valid_input;

	a = NULL;
	b = NULL;
	valid_input = collect_input(argc, argv, &a);
	if (!valid_input)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!sorted(&a))
	{
		if (stack_len(&a) == 2)
			sort_two(&a);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		sort(&a, &b);
	}
	return (clear_stack(&a), clear_stack(&b), EXIT_SUCCESS);
}
