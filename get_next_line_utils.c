/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_utils.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/30 15:48:22 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/31 15:34:15 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < count)
	{
		if (p[i] == (unsigned char)ch)
			return (p + i);
		i++;
	}
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	pdest = dest;
	psrc = src;
	i = 0;
	if (pdest == psrc)
		return (dest);
	while (i < n)
	{
		if (src > dest)
			pdest[i] = psrc[i];
		else
			pdest[n - 1 - i] = psrc[n - 1 - i];
		i++;
	}
	return (dest);
}
