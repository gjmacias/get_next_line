/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:29:29 by gmacias-          #+#    #+#             */
/*   Updated: 2022/03/26 21:49:59 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*the_rest(char *save)
{
	int		i;
	int		n;
	char	*new_save;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = malloc((ft_strlen(save) - i + 1) * sizeof(char));
	i++;
	n = 0;
	while (save[i] != '\0')
		new_save[n++] = save[i++];
	new_save[n] = '\0';
	free(save);
	return (new_save);
}

char	*make_line_from(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i - 1] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i - 1] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_until_enter(int fd, char *save)
{
	int		n_of_chars;
	char	*temp;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	n_of_chars = 1;
	while (ft_strchr(save, '\n') != -1 && n_of_chars != 0)
	{
		n_of_chars = read(fd, temp, BUFFER_SIZE);
		if (n_of_chars == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[n_of_chars] = '\0';
		save = ft_strjoin(save, temp);
	}
	free(temp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_until_enter(fd, save);
	if (save == NULL)
		return (NULL);
	line = make_line_from(save);
	save = the_rest(save);
	return (line);
}
