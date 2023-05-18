/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:29:46 by gmacias-          #+#    #+#             */
/*   Updated: 2022/03/27 11:02:38 by gmacias-         ###   ########.fr       */
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
/*	---		utils	---	*/
unsigned long int	ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *save, int character);
void				*ft_calloc(unsigned long int size, unsigned long int c);
#endif
