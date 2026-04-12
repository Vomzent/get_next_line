/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 10:36:09 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/12 13:12:43 by vcoevert     ########   odam.nl          */
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
	size_t	len;
	char	*ret;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	if (str)
		while (str[len])
			len++;
	ret = malloc(len + 1);
	if (ret)
	{
		*ret = 0;
		if (str)
			ft_strlcat(ret, str, len + 1);
		ft_strlcat(ret, buff, len + 1);
	}
	if (str)
		free(str);
	return (ret);
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
	printf("%s", ptr);
	return (0);
}
#endif
