/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.h                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 14:00:32 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/27 17:45:09 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>

typedef struct gnl_list
{
	char			chunk[BUFFER_SIZE];
	struct gnl_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*find_newline(char *chunk);
void	*list_clear(t_list *head);
t_list	*create_chunk(t_list *head, char *chunk);
void	lists_to_str(t_list *head, char *buff, char **ret);
void	clean_buffer(char *buff);
#endif
