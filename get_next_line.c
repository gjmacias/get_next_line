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

static unsigned long int	BUFFER_SIZE = 5;

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
	my_line = ft_strchr(sue, '\n');
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
	printf("%s, %lu, aqui esta ftread\n", sue, ft_strlen(sue));
	if (sue == NULL)
	{
		free(temp);
		free(sue);
		return (NULL);
	}
	while (*temp != '\0' || *temp != EOF || *temp != '\n')
		temp++;
	if (*temp != EOT || *temp != '\n')
	{
		free(temp);
		return (ft_read(fd, sue));
	}
	free(temp);
	return (sue);
}

int	main(void)
{
	int	fd = open("/home/gjmacias/ejercicios42/get_next_line/get_next_line/text.txt", O_RDONLY);
	printf("%sel final", get_next_line(fd));
	close(fd);
	return (0);
}
