/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 13:49:42 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/27 17:44:27 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*ret;
	t_list		*lst;
	t_list		*head;
	size_t		bytes_read;

	lst = 0;
	ret = buff;
	while (*ret && ret - buff < BUFFER_SIZE)
		ret++;
	bytes_read = BUFFER_SIZE;
	if (ret - buff != BUFFER_SIZE)
		bytes_read = read(fd, ret, BUFFER_SIZE);
	while (bytes_read == BUFFER_SIZE && !find_newline(buff))
	{
		head = create_chunk(lst, buff);
		if (!head)
			return (list_clear(lst));
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	lists_to_str(lst, buff, &ret);
	list_clear(lst);
	clean_buffer(buff);
	return (ret);
}
