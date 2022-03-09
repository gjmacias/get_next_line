/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:46:04 by gmacias-          #+#    #+#             */
/*   Updated: 2022/03/08 18:27:52 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

unsigned long int	ft_strlen(char *s)
{
	unsigned long int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s1[i++] != '\0')
		s[i - 1] = s1[i - 1];
	i = 0;
	while (s2[i++] != '\0')
	{
		s[ft_strlen(s1) + i - 1] = s2[i - 1];
	}
	s[ft_strlen(s1) + i - 1] = '\0';
	printf("%s, %i aqui acaba strjion\n", s, i);
	return (s);
}

char	*ft_strchr(char *sue, int character)
{
	char	*final;
	int	i;
	int	j;

	i = 0;	
	j = 0;
	while (sue[i] != character)
		i++;
	final = (char *)malloc((i + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	while (j <= i)
	{
		final[j] = sue[j];
		j++;
	}
	final[j] = '\0';
	return (final);
}
