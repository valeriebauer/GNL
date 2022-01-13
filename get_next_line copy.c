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

#include "get_next_line.h"

char    *ft_read(int fd, char *save)
{
    int read_buf;
    int flag_n;
    char *buf;

    read_buf = BUFFER_SIZE; // ou 1 ?
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
		return (NULL);
    if (save != NULL)
        flag_n = ft_find_n(save);
    while ((read_buf != 0) && (flag_n == 0))
    {
        read_buf = read(fd, buf, BUFFER_SIZE);
        if (read_buf < 0) // ou -1 ?
        {
            free(buf);
            return (NULL);
        }
        buf[read_buf] = '\0';
        printf("ft_read - buf[%d] = %s\n", read_buf, buf);
        printf("ft_read - av join - save = %s\n", save);
        save = ft_strjoin(save, buf);
        printf("ft_read - ap join - save = %s\n", save);
        flag_n = ft_find_n(save);
    }
    free(buf);
    return (save);
}

char    *ft_before_n(char **save)
{
    char    *before_n;
    int     i;

    i = 0;
    printf("ft_before_n - *save = %s\n", *save);
    while (((*save)[i] != '\n') && ((*save)[i] != '\0'))
        i++;
    printf("ft_before_n - (*save)[%d] = %c\n", i, (*save)[i]);
    if ((*save)[i] == '\n')
        before_n = malloc(sizeof(char) * (i + 1 + 1));
    if ((*save)[i] == '\0')
        before_n = malloc(sizeof(char) * (i + 1));
    if (before_n == NULL)
		return (NULL);
    ft_strcpy_n(before_n, *save);
    //printf("save avant le +i = %s\n", *save);
    if ((*save)[i] == '\n')
        (*save)++;
    *save = *save + i;
    printf("ft_before_n - sortie = %s\n", before_n);
    //printf("save apres le +i = %s\n", *save);
    return (before_n);
}

char    *ft_after__n(char *save)
{
    char    *after_n;
    //int     i;
    int     j;

    //i = 0;
    //// while ((save[i] != '\n') && (save[i] != '\0'))
    ////    i++;
    //// after_n = malloc(sizeof(char) * ft_strlen(save + i + 1));
    after_n = malloc(sizeof(char) * ft_strlen(save + 1));
    if (after_n == NULL)
		return (NULL);
    j = 0;
	while (save[j] != '\0')
	{
		after_n[j] = save[j];
		j++;
	}
	after_n[j] = '\0';
    printf("ft_after__n - after_n = %s\n", after_n);
    return (after_n);
}

char    *get_next_line(int fd)
{
    static char *save;
    char        *line;
   
    if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
    // AJOUTER 1 TEST ?
	save = ft_read(fd, save);
	if (save == NULL)
		return (NULL);
	if (!save[0])
	{
		free(save);
		save = NULL; 
		return (NULL);
	}
    printf("gnt - save = %s\n", save);
    line = ft_before_n(&save);
    save = ft_after__n(save);
    return (line);
}

int main(void)
{
    int fd;

    fd = open("input.txt", O_RDONLY);
    if (fd == -1)
                return (1);        // failed
    printf("\n******* GNT1 ********\n");
    printf("GNT1 - main - Ligne = %s\n", get_next_line(fd));
    printf("\n******* GNT2 ********\n");
    printf("GNT2 - main - Ligne = %s\n", get_next_line(fd));
    // printf("\n******* GNT3 ********\n");
    // printf("GNT3 - main - Ligne = %s\n", get_next_line(fd));
    // printf("\n******* GNT4 ********\n");
    // printf("GNT4 - main - Ligne = %s\n", get_next_line(fd));
    // printf("\n******* GNT5 ********\n");
    // printf("GNT5 - main - Ligne = %s\n", get_next_line(fd));
    if (close(fd) == -1)
        return (1);        // failed
    return (0);
}