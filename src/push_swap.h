/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:42:29 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/04 11:31:21 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h> 

typedef struct s_stack
{
	int				num;
	char			name;
	int				index;
	int				push_cost;
	bool			above_median;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target;
}		t_stack;

// Stack Utils

t_stack	*ft_stack_new(int num, char name);

void	update_median(t_stack **stack);

int		stack_len(t_stack **stack);

void	update_indices(t_stack **stack);

void	update_stack(t_stack **stack);

// Stack Utils 2

t_stack	*ft_stack_last(t_stack *stack);

void	ft_stack_add_back(t_stack **stack, t_stack *new);

void	ft_stack_addb_by_num(t_stack **stack, int num, char name);

t_stack	*get_node(t_stack **stack, int index);

// Clear mem

void	clear_stack(t_stack **stack);

void	clear_array(char **args);

// Stack simple operations

void	swap(t_stack **stack);

void	push(t_stack **a, t_stack **b, char na);

void	rotate(t_stack **stack);

void	reverse_rotate(t_stack **stack);

//Stack compound operations

void	ss(t_stack **a, t_stack **b);

void	rr(t_stack **a, t_stack **b);

void	rrr(t_stack **a, t_stack **b);

// Input checks

int		check_numbers(int argc, char **argv, t_stack **stack);

int		check_unique_stack(t_stack	**stack);

int		check_string(char *str, t_stack **stack);

// Input handles

int		collect_input(int argc, char **argv, t_stack **stack);

int		sorted(t_stack **stack);

// Sorting Utils

int		get_max(t_stack **stack);

int		get_min(t_stack **stack);

void	sort_two(t_stack **stack);

void	sort_three(t_stack **stack);

int		circularly_sorted(t_stack **stack);

// Sorting Utils 2

void	to_top(t_stack *node, t_stack **stack, char name);

void	both_to_top(t_stack *node_a, t_stack *node_b, t_stack **a, t_stack **b);

void	push_cheapest(t_stack *node, t_stack **a, t_stack **b);

void	move_both_up(t_stack *node, t_stack **a, t_stack **b);

void	move_both_down(t_stack *node, t_stack **a, t_stack **b);

// Cost analysis

void	set_target_smaller_node(t_stack *node, t_stack **stack);

int		calc_pushcost_node(t_stack *node, t_stack **a, t_stack **b);

void	set_target_smaller_stack(t_stack **a, t_stack **b);

void	set_push_cost(t_stack **a, t_stack **b);

t_stack	*find_cheapest(t_stack **stack);

void	set_target_bigger_node(t_stack *node, t_stack **stack);

// Sorting

void	sort(t_stack **a, t_stack **b);

void	shift(t_stack **stack);

void	return_sorted(t_stack **a, t_stack **b);

void	push_to_aux_stack(t_stack **a, t_stack **b);

void	shift_desc(t_stack **stack);

//Checker Utils

int		execute_one(t_stack **a, t_stack **b, char *op);

int		execute_rotate(t_stack **a, t_stack **b, char *op);

void	execute(t_stack **a, t_stack **b);

// Debugging

void	pretty_print_stack(t_stack **stack);

void	verbose_print_node(t_stack *node);

void	verbose_print_stack(t_stack **stack);

#endif