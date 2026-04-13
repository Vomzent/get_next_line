/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_utils.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 12:12:04 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/13 11:03:34 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#if EVAL
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#endif

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if ((char)ch == '\0')
		return ((char *)str + i);
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	srclen = 0;
	destlen = 0;
	i = 0;
	while (src[srclen])
		srclen++;
	if (!size)
		return (srclen);
	while (dst[destlen] && destlen < size)
		destlen++;
	if (dst[destlen])
		return (srclen + destlen);
	while (src[i] && i + destlen + 1 < size)
	{
		dst[i + destlen] = src[i];
		i++;
	}
	dst[i + destlen] = '\0';
	return (srclen + destlen);
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
