/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_utils_bonus.c                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/30 15:48:22 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/01 12:52:28 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	pdest = dest;
	psrc = src;
	if (psrc == pdest)
		return (dest);
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
