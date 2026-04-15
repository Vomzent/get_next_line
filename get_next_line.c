/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 10:36:09 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/15 21:26:15 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif

static char	*append_chunk(char *str, char *buff)
{
	size_t	strlen;
	size_t	bufflen;
	char	*ret;

	bufflen = 0;
	strlen = 0;
	while (buff[bufflen] && buff[bufflen] != '\n')
		bufflen++;
	if (buff[bufflen] == '\n')
		bufflen++;
	if (str)
		while (str[strlen])
			strlen++;
	ret = malloc(strlen + bufflen + 1);
	if (ret)
	{
		*ret = '\0';
		if (str)
			gnl_strlcat(ret, str, strlen + bufflen + 1);
		gnl_strlcat(ret, buff, strlen + bufflen + 1);
	}
	if (str)
		free(str);
	return (ret);
}

static void	clean_buffer(char *buff)
{
	char	*fillpoint;

	fillpoint = gnl_strchr(buff, '\n') + 1;
	*buff = '\0';
	if (fillpoint != (char *)1)
		gnl_strlcat(buff, fillpoint, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*ret;

	if (!*buff)
	{
		gnl_memset(buff, 0, BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE) == -1)
			return (0);
	}
	ret = 0;
	while (!gnl_strchr(buff, '\n') && *buff)
	{
		ret = append_chunk(ret, buff);
		gnl_memset(buff, 0, BUFFER_SIZE);
		if (read(fd, buff, BUFFER_SIZE) == -1)
		{
			if (ret)
				free(ret);
			return (0);
		}
	}
	if (*buff)
		ret = append_chunk(ret, buff);
	clean_buffer(buff);
	return (ret);
}
