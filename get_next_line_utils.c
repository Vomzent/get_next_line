/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_utils.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/25 11:45:11 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/27 17:50:55 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*list_clear(t_list *head)
{
	t_list	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	return (head);
}

char	*find_newline(char *chunk)
{
	size_t	i;

	i = -1;
	while (++i < BUFFER_SIZE)
	{
		if (chunk[i] == '\n' || chunk[i] == '\0')
			return (chunk + i);
	}
	return (0);
}

void	clean_buffer(char *chunk)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = find_newline(chunk) - chunk;
	j++;
	while (j < BUFFER_SIZE)
		chunk[i++] = chunk[j++];
	while (i < BUFFER_SIZE)
		chunk[i++] = '\0';
}

t_list	*create_chunk(t_list *head, char *chunk)
{
	t_list	*ret;
	size_t	i;

	i = -1;
	ret = malloc(sizeof(t_list));
	if (!ret)
		return (ret);
	while (++i < BUFFER_SIZE)
		ret->chunk[i] = chunk[i];
	ret->next = 0;
	if (!head)
	{
		head = ret;
		return (ret);
	}
	while (head->next)
		head = head->next;
	head->next = ret;
	return (ret);
}

void	lists_to_str(t_list *head, char *buff, char **ret)
{
	t_list	*temp;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	temp = head;
	while (head)
	{
		head = head->next;
		i++;
	}
	size = find_newline(buff) - buff;
	ret[0] = malloc(sizeof(t_list) * i + size + 1);
	j = 0;
	while (temp)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			ret[0][j++] = temp->chunk[i++];
	}
	i = 0;
	while (i < size)
		ret[0][j++] = buff[i++];
	ret[0][j] = '\0';
}
