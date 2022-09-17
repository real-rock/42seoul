/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:38:58 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/09 15:39:32 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

typedef void	(*t_sa_handler)(int);
typedef void	(*t_sa_sigaction)(int, siginfo_t *, void *);

typedef struct s_bit_field_8
{
	unsigned char	bit_1:1;
	unsigned char	bit_2:1;
	unsigned char	bit_3:1;
	unsigned char	bit_4:1;
	unsigned char	bit_5:1;
	unsigned char	bit_6:1;
	unsigned char	bit_7:1;
	unsigned char	bit_8:1;
}			t_bit_field_8;

typedef struct s_message
{
	unsigned int	index;
	t_bit_field_8	bit_field;
}			t_message;

#endif