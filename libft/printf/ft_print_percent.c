/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_percent.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/26 13:33:32 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/06 13:27:39 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int	ft_print_percent(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}
