/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 16:40:36 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/28 16:19:46 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <limits.h>

static bool	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	is_integer(char *str, t_stack **stack)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	nb *= sign;
	if (*str)
		return (0);
	if (nb >= INT_MIN && nb <= INT_MAX)
		ft_stack_addb_by_num(stack, (int)nb, 'a');
	return (nb >= INT_MIN && nb <= INT_MAX);
}

int	check_unique_stack(t_stack	**stack)
{
	t_stack	*node;
	t_stack	*temp;

	node = *stack;
	if (!node)
		return (0);
	while (node)
	{
		temp = node->next;
		while (temp)
		{
			if (node->num == temp->num)
				return (0);
			temp = temp->next;
		}
		node = node->next;
	}
	return (1);
}

/* Checks that the input contains only integers 
and if successful, puts the numbers in the stack*/
int	check_numbers(int argc, char **argv, t_stack **stack)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (!is_integer(argv[i + 1], stack))
			return (clear_stack(stack), 0);
		i++;
	}
	if (!check_unique_stack(stack))
		return (clear_stack(stack), 0);
	return (1);
}

/* Checks that the input string consists only of valid integers*/
int	check_string(char *str, t_stack **stack)
{
	char	**args;
	int		i;

	args = ft_split(str, ' ');
	i = 0;
	while (args[i])
	{
		if (!is_integer(args[i], stack))
			return (clear_stack(stack), clear_array(args), 0);
		i++;
	}
	if (!check_unique_stack(stack))
		return (clear_stack(stack), clear_array(args), 0);
	clear_array(args);
	return (1);
}
