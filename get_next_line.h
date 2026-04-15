/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line.h                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 11:40:50 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/15 20:17:51 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

char	*get_next_line(int fd);
void	*gnl_memset(void *s, int c, size_t n);
char	*gnl_strchr(const char *str, int ch);
size_t	gnl_strlcat(char *dst, const char *src, size_t size);
#endif
