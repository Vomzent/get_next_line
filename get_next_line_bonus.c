/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_bonus.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 10:36:09 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/15 21:13:02 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif
#if EVAL
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
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
			gnl_b_strlcat(ret, str, strlen + bufflen + 1);
		gnl_b_strlcat(ret, buff, strlen + bufflen + 1);
	}
	if (str)
		free(str);
	return (ret);
}

static void	clean_buffer(char *buff)
{
	char	*fillpoint;

	fillpoint = gnl_b_strchr(buff, '\n') + 1;
	*buff = '\0';
	if (fillpoint != (char *)1)
		gnl_b_strlcat(buff, fillpoint, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	buff[FD_SETSIZE][BUFFER_SIZE + 1];
	char		*ret;

	if (!buff[fd][0])
	{
		gnl_b_memset(buff[fd], 0, BUFFER_SIZE);
		if (read(fd, buff[fd], BUFFER_SIZE) == -1)
			return (0);
	}
	ret = 0;
	while (!gnl_b_strchr(buff[fd], '\n') && buff[fd][0])
	{
		ret = append_chunk(ret, buff[fd]);
		gnl_b_memset(buff[fd], 0, BUFFER_SIZE);
		if (read(fd, buff[fd], BUFFER_SIZE) == -1)
		{
			if (ret)
				free(ret);
			return (0);
		}
	}
	if (buff[fd][0])
		ret = append_chunk(ret, buff[fd]);
	clean_buffer(buff[fd]);
	return (ret);
}

#if EVAL

int	main(int argc, char **argv)
{
	char	*ptr;
	int		fd;

	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ptr = get_next_line(fd);
	while (ptr)
	{
		printf("%s", ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
	return (0);
}
#endif
