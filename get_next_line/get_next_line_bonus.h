/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:14:15 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/27 10:01:59 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE	42
# endif

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_info
{
	char	buff[BUFF_SIZE];
	int		line_break_idx;
	bool	flag;
}	t_info;

char		*get_next_line(int fd);
int			check_line_break(char *buff, int read_size, int start_idx);
int			ft_read(int fd, t_info *info, char **str);
int			ft_continue(t_info *info, char **str);
void		clean_buff(char *buff);

char		*ft_strnjoin(char *s1, const char *s2, int len);
void		ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_substr(const char *s, size_t start_idx, size_t end_idx);

#endif