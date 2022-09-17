/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:14:13 by jiheo             #+#    #+#             */
/*   Updated: 2021/12/23 18:34:41 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	idx;
	size_t	s1_len;

	idx = 0;
	s1_len = ft_strlen(s1);
	while (s2[idx] && idx < n)
	{
		s1[s1_len + idx] = s2[idx];
		idx++;
	}
	s1[s1_len + idx] = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	if (str == NULL)
		return (0);
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strnjoin(char *s1, const char *s2, int len)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_substr(s2, 0, (size_t)len - 1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len > (size_t)len)
		s2_len = (size_t)len;
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	ft_strncat(res, s1, s1_len);
	ft_strncat(res, s2, s2_len);
	free(s1);
	return (res);
}

char	*ft_substr(const char *s, size_t start_idx, size_t end_idx)
{
	char	*res;
	size_t	idx;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start_idx || s_len < end_idx || start_idx > end_idx)
		return (NULL);
	res = (char *)malloc((end_idx - start_idx + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (start_idx <= end_idx)
		res[idx++] = s[start_idx++];
	res[idx] = 0;
	return (res);
}
