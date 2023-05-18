/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:29:46 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/16 14:38:42 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char				*the_rest(char *save);
char				*make_line_from(char *save);
char				*read_until_enter(int fd, char *save);
char				*get_next_line(int fd);
unsigned long int	ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strchr(char *sue, int character);
#endif
