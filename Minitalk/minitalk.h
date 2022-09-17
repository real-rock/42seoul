/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:45:46 by jiheo             #+#    #+#             */
/*   Updated: 2022/01/09 15:40:37 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <limits.h>
# include "ft_type.h"

int				ft_atoi(const char *str);
void			ft_putnbr(const int n);
void			ft_putstr(const char *str);
size_t			ft_strlen(const char *str);

t_bit_field_8	convert_uchar_to_bit(unsigned char c);
void			print_bit_to_uchar(t_bit_field_8 *bit_field);
unsigned char	convert_bit_to_uchar(t_bit_field_8 *bit_field);

void			send_a_string_with_null(const char *str, int pid);

void			set_sa_client(struct sigaction *sa, \
								t_sa_handler handler);
void			set_sa_server(struct sigaction *sa, \
								t_sa_sigaction handler);

#endif