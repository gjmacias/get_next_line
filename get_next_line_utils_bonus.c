/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:46:04 by gmacias-          #+#    #+#             */
/*   Updated: 2022/03/27 11:01:08 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

unsigned long int	ft_strlen(char *s)
{
	unsigned long int	i;

	i = 0;
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
	if (s1 == NULL || s2 == NULL)
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
	free(s1);
	return (s);
}

int	ft_strchr(char *save, int character)
{
	unsigned long int	i;

	if (save == NULL)
		return (1);
	i = 0;
	while (save[i] != character && save[i] != '\0')
		i++;
	if (save[i] == character)
		return (-1);
	return (1);
}
