/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/03/24 15:16:29 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/03/29 16:43:20 by vcoevert     ########   odam.nl          */
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

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*ptr;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		ptr = get_next_line(fd);
		while (*ptr)
		{
			write(1, ptr, strlen(ptr));
			free(ptr);
			ptr = get_next_line(fd);
		}
		free(ptr);
		i++;
	}
	return (0);
}
