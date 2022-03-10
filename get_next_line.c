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
#include <unistd.h>
#include <stdio.h>

char	*ft_read(int fd, char *sue);

char	*get_next_line(int fd)
{
	char				*my_line;
	static char			*save_until_enter;
	unsigned long int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	if (save_until_enter == NULL)
	{
		my_line = (char *)malloc(sizeof(char));
		my_line[0] = '\0';
	}
	else
		my_line = save_until_enter;
	save_until_enter = ft_read(fd, my_line);
	if (save_until_enter == NULL)
		return (NULL);
	my_line = ft_strchr(save_until_enter, '\n');
	while (save_until_enter[i] != '\n')
		i++;
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
	while (*temp != '\0' && *temp != EOF && *temp != '\n')
		temp++;
	if (*temp != EOF && *temp != '\n')
	{
		//free(temp);
		return (ft_read(fd, sue));
	}
	//free(temp);
	return (sue);
}
