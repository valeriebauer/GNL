/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:50:48 by vbauer            #+#    #+#             */
/*   Updated: 2022/01/14 18:51:51 by vbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	return (NULL);
}

int	main(void)
{
	int		fd;
	int		end_buf;
	char	*buf;
	char	*line;

	end_buf = BUFFER_SIZE;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	fd = open("input.txt", O_RDONLY);
	if (fd == -1)
		return (1);		   // failed
   // Lecture de tout le fichier par "pas de" de BUFFER_SIZE, ne tient pas compte du \n
	while (end_buf == BUFFER_SIZE) // ATTENTION : 1 tour de trop si taille fichier = multiple de B_S
	{
		end_buf = read(fd, buf, BUFFER_SIZE);
		buf[end_buf] = '\0'; // permet de remettre a 0 le buffer avant de relire
		printf("buf[%d] = %s\n", end_buf, buf);
	}
	if (close(fd) == -1)
	{
			return (1);		   // failed
	}
	return (0);
}
