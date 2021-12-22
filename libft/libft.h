/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:16:59 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 17:17:01 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** libft functions **
*/
int		ft_hex_len(unsigned int number);
int		ft_long_len(unsigned long number);
int		ft_numberlen(int number);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putnbr_uns(unsigned int nb);
void	ft_putstr(char *str);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
int		ft_unsigned_len(unsigned int number);
void	free_str(char *str);
int		nb_point_count(int number);
/*
** end libft functions **
*/

#endif
