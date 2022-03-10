/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:29:46 by gmacias-          #+#    #+#             */
/*   Updated: 2022/03/08 17:11:27 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char				*ft_read(int fd, char *sue);
char				*get_next_line(int fd);
unsigned long int	ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *sue, int character);
#endif
