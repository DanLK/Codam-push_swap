/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:05:04 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/31 12:19:49 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

t_gnl_list	*ft_gnl_lstnew(char *content)
{
	t_gnl_list	*new;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!new)
		return (NULL);
	new->content = (char *)content;
	new->next = 0;
	return (new);
}

void	ft_gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new_node)
{
	t_gnl_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_gnl_lstlast(*lst);
	last->next = new_node;
}

t_gnl_list	*ft_gnl_lstlast(t_gnl_list *lst)
{
	t_gnl_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	find_new_line(t_gnl_list *node, char mode)
{
	int	i;
	int	count;

	count = 0;
	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == '\n')
				return (++count);
			i++;
			count++;
		}
		node = node->next;
	}
	if (mode == 'f')
		return (0);
	else if (mode == 'c')
		return (count);
	else
		return (-1);
}

void	clear_list(t_gnl_list **list, t_gnl_list *node, char *content)
{
	t_gnl_list	*to_clear;
	t_gnl_list	*temp;

	if (list == NULL)
		return ;
	to_clear = *list;
	while (to_clear)
	{
		temp = to_clear->next;
		free(to_clear->content);
		free(to_clear);
		to_clear = temp;
	}
	if (node != NULL && node->content != NULL && node->content[0])
	{
		*list = node;
	}
	else
	{
		free(node);
		free(content);
		*list = NULL;
	}
}
