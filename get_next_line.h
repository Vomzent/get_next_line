/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.h                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 14:00:32 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/24 14:26:24 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

typedef struct gnl_list
{
	char			chunk[BUFFER_SIZE];
	struct gnl_list	*next;
}					c_list;

char	*get_next_line(int fd);
#endif
