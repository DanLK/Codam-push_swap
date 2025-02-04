/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 11:58:48 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/06 13:27:41 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int	ft_printc(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
