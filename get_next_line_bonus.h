/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_bonus.h                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/12 11:40:50 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/15 21:09:50 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>

char	*get_next_line(int fd);
void	*gnl_b_memset(void *s, int c, size_t n);
char	*gnl_b_strchr(const char *str, int ch);
size_t	gnl_b_strlcat(char *dst, const char *src, size_t size);
#endif
