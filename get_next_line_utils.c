/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauer <vbauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:03:47 by vbauer            #+#    #+#             */
/*   Updated: 2022/01/10 13:04:06 by vbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy_n(char *dest, char *src)
{
	int	i;

	i = 0;
	while ((src[i] != '\0') && (src[i] != '\n'))
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*ft_find_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_first_save(void)
{
	char	*d;

	d = malloc(sizeof(char) * 1);
	if (d == NULL)
		return (NULL);
	d = "";
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_first_save();
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i+j] = s2[j];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}