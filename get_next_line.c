/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 13:49:42 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/24 15:46:56 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*ret;
	c_list		*head;
	c_list		*next;
	size_t		i;
	size_t		j;

	head = 0;
	i = 0;
	while (i < 4)
	{
		next = malloc(sizeof(c_list));
		if (!next)
			return(0);
		next->next = head;
		head = next;
		i++;
	}
	while (head)
	{
		i = 0;
		read(fd, buff, BUFFER_SIZE);
		while (i < BUFFER_SIZE)
		{
			head->chunk[i] = buff[i];
			i++;
		}
		head = head->next;
	}
	ret = malloc((sizeof(BUFFER_SIZE) * 4) + 1);
	i = 0;
	head = next;
	while (head)
	{
		j = 0;
		while (j < BUFFER_SIZE)
			ret[i++] = head->chunk[j++];
		next = head->next;
		free(head);
		head = next;
	}
	ret[i] = '\0';
	return (ret);
}
