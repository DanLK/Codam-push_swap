/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prints.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 11:44:30 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/06 13:30:55 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int	ft_prints(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (6);
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

// #include <stdio.h>

// int	main(void)
// {
// 	// char	s[] = "";

// 	printf("%s\n", (char *)NULL);
// 	printf("\n");
// 	printf("\nBytes printed: %d\n", ft_prints(NULL));
// 	return (0);
// }