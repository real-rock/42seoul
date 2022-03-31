/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:39:41 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/23 18:40:49 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("files/43_char", O_RDWR);
	printf("\n%d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
	}
	fd = open("files/mix_marge1", O_RDWR);
	printf("\n%d\n", fd);
	str = get_next_line(fd);
	printf("%s", str);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
	}
}
