/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:52:25 by vbauer            #+#    #+#             */
/*   Updated: 2022/01/17 15:51:20 by vbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *save)
{
	int		read_buf;
	char	*buf;

	read_buf = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while ((read_buf != 0) && (!ft_find_n(save)))
	{
		read_buf = read(fd, buf, BUFFER_SIZE);
		if (read_buf == -1)
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

static char	*ft_before_n(char *save)
{
	char	*before_n;
	int		i;

	i = 0;
	while ((save[i] != '\n') && (save[i] != '\0'))
		i++;
	if (save[i] == '\n')
		before_n = malloc(sizeof(char) * (i + 1 + 1));
	else
		before_n = malloc(sizeof(char) * (i + 1));
	if (before_n == NULL)
		return (NULL);
	ft_strcpy_n(before_n, save);
	return (before_n);
}

static char	*ft_after__n(char *save)
{
	char	*after_n;
	int		i;
	int		j;

	i = 0;
	while ((save[i] != '\n') && (save[i] != '\0'))
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	after_n = malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (after_n == NULL)
		return (NULL);
	i++;
	j = 0;
	while (save[i + j] != '\0')
	{
		after_n[j] = save[i + j];
		j++;
	}
	after_n[j] = '\0';
	free(save);
	return (after_n);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, NULL, 0) == -1))
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (save[fd][0] == '\0')
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	line = ft_before_n(save[fd]);
	save[fd] = ft_after__n(save[fd]);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	int fd1;

// 	fd = open("text.txt", O_RDONLY);
// 	fd1 = open("text2.txt", O_RDONLY);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));

// 	return (0);

// }
