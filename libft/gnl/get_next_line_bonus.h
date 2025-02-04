/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:04:59 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/31 14:58:35 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 28

# endif

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
void		read_to_list(int fd, t_gnl_list **list);
char		*get_current_line(t_gnl_list *head);
void		copy_line(t_gnl_list *head, char *line);
void		set_list(t_gnl_list **list);

// UTILS

t_gnl_list	*ft_gnl_lstnew(char *content);
void		ft_gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new_node);
t_gnl_list	*ft_gnl_lstlast(t_gnl_list *lst);
int			find_new_line(t_gnl_list *node, char mode);
void		clear_list(t_gnl_list **list, t_gnl_list *node, char *content);

#endif