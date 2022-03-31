/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:14:15 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/27 10:03:09 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE	42
# endif

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

char		*get_next_line(int fd);
int			check_line_break(char *buff, int read_size, int start_idx);
int			ft_read(int fd, char *buff, char **str, int *line_break);
int			ft_continue(char *buff, int *line_break, char **str);
void		clean_buff(char *buff);

char		*ft_strnjoin(char *s1, const char *s2, int len);
void		ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_substr(const char *s, size_t start_idx, size_t end_idx);

#endif