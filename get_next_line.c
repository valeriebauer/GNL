/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauer <vbauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:51:19 by vbauer            #+#    #+#             */
/*   Updated: 2022/01/06 15:51:26 by vbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

char    *ft_read(char *save, int fd)
{
    int read_buf;
    char *buf;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
		return (NULL);
    while ((read_buf != 0) && (!ft_find_n(buf))
    {        
        read_buf = read(fd, buf, BUFFER_SIZE);
        if (read_buf < 0) // ou -1 ?
        {
            free(buf);
            return (NULL);
        }
        buf[read_buf] = '\0';
        save = ft_strjoin(save, buf);
    }
    free(buf);
    return (save);
}

char    *ft_before_n(char *save)
{
    char    *before_n;
    int     i;

    i = 0;
    while ((save[i] != '\n') && (save[i] != '\0'))
        i++;
    if (save[i] == '\n')
        before_n = malloc(sizeof(char) * (i + 1 + 1));
    if (save[i] == '\0')
        before_n = malloc(sizeof(char) * (i + 1));
    if (before_n == NULL)
		return (NULL);
    ft_strcpy_n(before_n, save);
    return (before_n)
}

char    *ft_after_n(char *save)
{
    char    *after_n;
    int     i;
    int     j;

    i = 0;
    while ((save[i] != '\n') && (save[i] != '\0'))
        i++;
    after_n = malloc(sizeof(char) * (ft_strlen(&save[i]) + 1));
    if (after_n == NULL)
		return (NULL);
    j = 0;
	while (save[i+j] != '\0')
	{
		after_n[j] = save[i+j];
		j++;
	}
	after_n[j] = '\0';
    return (after_n)
}

char    *get_next_line(int fd)
{
    static char *save;
    char        *line;

if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	save = ft_read(save, fd);
	if (save == NULL)
		return (NULL);
	if (save[0] == '')
	{
		free(save);
		//save = NULL; ????????????????
		return (NULL);
	}
    line = ft_before_n(save);
	save = ft_after__n(save);
    return (line);
}

int main(void)
{
    int fd;
    int read_buf;
    char *buf;
    char *line;

    read_buf = BUFFER_SIZE;
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
		return (0);
    fd = open("input.txt", O_RDONLY);
    if (fd == -1)
                return (1);        // failed
    printf("Ligne = %s\n", get_next_line(fd));
    if (close(fd) == -1)
    {
            return (1);        // failed
    }
    return (0)
}