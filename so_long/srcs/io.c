/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:39:29 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/26 19:17:43 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/io.h"

int	open_file(const char *src)
{
	int	fd;

	fd = open(src, O_RDONLY);
	if (fd <= 0)
		gen_err_with_no();
	return (fd);
}

void	close_file(int fd)
{
	close(fd);
}
