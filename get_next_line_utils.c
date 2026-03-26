/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_utils.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/25 11:45:11 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/26 17:23:46 by vcoevert     ########   odam.nl          */
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

// size_t	strlen(char *chunk)
// {
// 	size_t
// }

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

char	*lists_to_str(t_list *head, char *buff)
{
	char	*ret;
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
	ret = malloc(sizeof(t_list) * i + size + 1);
	j = 0;
	while (temp)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			ret[j++] = temp->chunk[i++];
	}
	i = 0;
	while (i < size)
		ret[j++] = buff[i++];
	ret[j] = '\0';
	return (ret);
}
