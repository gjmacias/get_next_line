/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:29:29 by gmacias-          #+#    #+#             */
/*   Updated: 2022/03/08 18:27:54 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_read(int fd, char *sue);

char	*get_next_line(int fd)
{
	char				*my_line;
	static char			*save_until_enter;
	unsigned long int	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_until_enter = ft_read(fd, save_until_enter);
	if (save_until_enter == NULL)
		return (NULL);
	my_line = (char *)malloc(sizeof(char) * (ft_strlen(save_until_enter) + 1));
	while (save_until_enter[i] != '\n')
	{
		my_line[i] = save_until_enter[i];
		i++;
	}
	save_until_enter = &save_until_enter[i];
	return (my_line);
}

char	*ft_read(int fd, char *sue)
{
	char		*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	if (-1 == read(fd, temp, BUFFER_SIZE))
	{
		free(temp);
		return (NULL);
	}
	sue = ft_strjoin(sue, temp);
	if (sue == NULL)
	{
		free(temp);
		free(sue);
		return (NULL);
	}
	while (*temp != '\0')
	{
		if (*temp == '\n')
		{
			return (sue);
		}
		temp++;
	}
	free(temp);
	return (ft_read(fd, sue));
}
