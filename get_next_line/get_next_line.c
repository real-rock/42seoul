/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:14:18 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/27 10:04:43 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFF_SIZE] = {0, };
	static int	line_break_idx = -1;
	int			eof;
	char		*res;

	res = NULL;
	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	while (true)
	{
		if (line_break_idx == -1)
			eof = ft_read(fd, buff, &res, &line_break_idx);
		else
			eof = ft_continue(buff, &line_break_idx, &res);
		if (eof)
			return (res);
		clean_buff(buff);
	}
}

int	ft_read(int fd, char *buff, char **str, int *line_break)
{
	int	read_size;

	read_size = read(fd, buff, BUFF_SIZE);
	if (read_size < 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	if (read_size == 0)
		return (1);
	*line_break = check_line_break(buff, read_size, 0);
	if (*line_break != -1)
	{
		*str = ft_strnjoin(*str, buff, *line_break + 1);
		return (1);
	}
	*str = ft_strnjoin(*str, buff, read_size);
	return (0);
}

int	ft_continue(char *buff, int *line_break, char **str)
{
	int		new_line_break;
	char	*new_str;

	new_line_break = check_line_break(buff, BUFF_SIZE, *line_break + 1);
	if (new_line_break != -1)
	{
		free(*str);
		*str = ft_substr(buff, *line_break + 1, new_line_break);
		*line_break = new_line_break;
		return (1);
	}
	new_str = ft_substr(buff, (size_t)(*line_break) + 1, ft_strlen(buff));
	*str = ft_strnjoin(*str, new_str, ft_strlen(new_str));
	free(new_str);
	(*line_break) = -1;
	return (0);
}

void	clean_buff(char *buff)
{
	size_t	idx;

	idx = 0;
	while (idx < BUFF_SIZE)
		buff[idx++] = 0;
}

int	check_line_break(char *buff, int read_size, int start_idx)
{
	while (start_idx < read_size)
	{
		if (buff[start_idx] == '\n')
			return (start_idx);
		start_idx++;
	}
	return (-1);
}
