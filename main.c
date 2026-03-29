/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 15:16:29 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/29 15:25:45 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("./hello.txt", O_RDWR);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	ptr = get_next_line(fd);
	write(1, ptr, strlen(ptr));
	free(ptr);
	close(fd);
	return (0);
}
