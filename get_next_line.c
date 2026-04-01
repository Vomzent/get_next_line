/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/30 15:35:05 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/01 11:12:19 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static ssize_t	fill_buff(char *buff, int fd)
{
	char	*fillpoint;
	size_t	in_buff;
	ssize_t	bytes_read;

	fillpoint = ft_strchr(buff, '\n');
	in_buff = BUFFER_SIZE;
	if (fillpoint)
	{
		in_buff = fillpoint - buff;
		ft_memcpy(buff, fillpoint + 1, BUFFER_SIZE - in_buff);
		ft_memset(buff + (BUFFER_SIZE - in_buff), '\0', 1);
	}
	fillpoint = ft_strchr(buff, '\0');
	bytes_read = 0;
	if (fillpoint)
	{
		in_buff = fillpoint - buff;
		bytes_read = read(fd, fillpoint, BUFFER_SIZE - in_buff);
	}
	if (bytes_read == -1)
		return (-1);
	in_buff += bytes_read;
	ft_memset(buff + in_buff, 0, (BUFFER_SIZE - in_buff > 0));
	return (in_buff);
}

static char	*make_ret(char *str, char *buff)
{
	size_t	slen;
	size_t	blen;
	char	*bend;
	char	*ret;

	slen = 0;
	bend = ft_strchr(buff, '\n') + 1;
	if (bend == (char *)1)
		bend = ft_strchr(buff, '\0');
	blen = bend - buff;
	if (str)
		while (str[slen])
			slen++;
	ret = malloc(slen + blen + 1);
	if (!ret)
		return (free(str), (char *)0);
	if (str)
	{
		ft_memcpy(ret, str, slen);
		free(str);
	}
	ft_memcpy(ret + slen, buff, blen);
	ft_memset(ret + slen + blen, '\0', 1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 2];
	char		*ret;
	ssize_t		buff_bytes;

	buff_bytes = fill_buff(buff, fd);
	if (buff_bytes == -1)
		return (0);
	ret = 0;
	while (!ft_strchr(buff, '\n') && *buff)
	{
		ret = make_ret(ret, buff);
		ft_memset(buff, '\0', BUFFER_SIZE);
		buff_bytes = fill_buff(buff, fd);
		if (buff_bytes == -1)
			return (free(ret), (char *)0);
	}
	ret = make_ret(ret, buff);
	if (ret)
		if (!*ret)
			return (free(ret), (char *)0);
	return (ret);
}
