/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printu.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 14:38:13 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/06 13:31:13 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int	ft_printu(unsigned int x)
{
	char	buffer[11];
	char	*str;

	str = buffer + 11;
	*--str = '\0';
	if (x == 0)
		*--str = '0';
	while (x > 0)
	{
		*--str = x % 10 + '0';
		x /= 10;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	// printf("%u\n", (unsigned int)4294967295);
// 	printf("\nBytes printed: %d\n", ft_printu(LONG_MIN));
// 	return (0);
// }