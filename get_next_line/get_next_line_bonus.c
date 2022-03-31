/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:14:18 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/27 10:04:59 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_info	container[OPEN_MAX + 1];
	int				eof;
	char			*res;

	res = NULL;
	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	while (true)
	{
		if (container[fd].flag)
			eof = ft_continue(&container[fd], &res);
		else
			eof = ft_read(fd, &container[fd], &res);
		if (eof)
			return (res);
		clean_buff(container[fd].buff);
	}
}

int	ft_read(int fd, t_info *info, char **str)
{
	int	read_size;

	read_size = read(fd, info->buff, BUFF_SIZE);
	if (read_size < 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	if (read_size == 0)
		return (1);
	info->line_break_idx = check_line_break(info->buff, read_size, 0);
	info->flag = 1;
	if (info->line_break_idx != -1)
	{
		*str = ft_strnjoin(*str, info->buff, info->line_break_idx + 1);
		return (1);
	}
	*str = ft_strnjoin(*str, info->buff, read_size);
	return (0);
}

int	ft_continue(t_info *info, char **str)
{
	int		new_line_break;
	char	*new_str;

	new_line_break = check_line_break(info->buff, BUFF_SIZE, \
										info->line_break_idx + 1);
	if (new_line_break != -1)
	{
		free(*str);
		*str = ft_substr(info->buff, \
						info->line_break_idx + 1, new_line_break);
		info->line_break_idx = new_line_break;
		return (1);
	}
	new_str = ft_substr(info->buff, \
						(size_t)(info->line_break_idx) + 1, \
						ft_strlen(info->buff));
	*str = ft_strnjoin(*str, new_str, ft_strlen(new_str));
	free(new_str);
	info->flag = 0;
	info->line_break_idx = -1;
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
