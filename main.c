/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 15:16:29 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/24 15:31:58 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int		fd = open("./hello.txt", O_RDWR);
	char	*ptr;

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	return (0);
}
