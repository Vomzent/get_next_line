/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 10:36:09 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/13 01:45:16 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
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
			ft_strlcat(ret, str, strlen + bufflen + 1);
		ft_strlcat(ret, buff, strlen + bufflen + 1);
	}
	if (str)
		free(str);
	return (ret);
}

static void	clean_buffer(char *buff)
{
	char	*fillpoint;

	fillpoint = ft_strchr(buff,'\n') + 1;
	*buff = '\0';
	if (fillpoint != (char *)1)
		ft_strlcat(buff, fillpoint, BUFFER_SIZE);
	else
		ft_memset(buff, 0, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*ret;

	if (!*buff)
		if (read(fd, buff, BUFFER_SIZE) == -1)
			return (0);
	ret = 0;
	while (!ft_strchr(buff, '\n') && *buff)
	{
		ret = append_chunk(ret, buff);
		ft_memset(buff, 0, BUFFER_SIZE);
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
		printf("> %s", ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
	return (0);
}
#endif
