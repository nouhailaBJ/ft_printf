/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:51:33 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 18:04:48 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_info
{
	const char	*str;
	char		flags[2];
	int			width;
	int			pressesion;
	int			count;
	int			i;
	int			negative;
}				t_info;

/*
** ft_printf.c functions **
*/
void			initialisation(t_info *info);
void			re_initialisation(t_info *info);
void			ft_conversion(t_info *info, va_list args);
void			basic_printf(t_info *info, va_list args);
int				ft_printf(const char *str, ...);

/*
** basic_function1.c functions **
*/
int				calcul_width(t_info *info);
int				calcul_pressesion(t_info *info);
void			display_str(t_info *info, va_list args);
void			find_conversion(t_info *info, va_list args);
void			find_flag(t_info *info, va_list args);

/*
** basic_function2.c functions **
*/
void			print_zero_module(t_info *info);
void			print_negative_module(t_info *info);
void			print_width_module(t_info *info);
void			print_zero(t_info *info, int tmp);
void			print_space(t_info *info, int tmp);

/*
** flags.c functions **
*/
void			flag_negative(t_info *info, va_list args);
void			flag_zero(t_info *info, va_list args);
void			flag_star(t_info *info, va_list args);
void			flag_width(t_info *info, va_list args);
void			flag_point(t_info *info, va_list args);

/*
** ft_int.c functions **
*/
void			print_int(t_info *info, va_list args);
void			nega_point_int(t_info *info, va_list args);
void			nega_int(t_info *info, va_list args);
void			point_int(t_info *info, va_list args);
void			zero_point_int(t_info *info, va_list args);

/*
** ft_int2.c functions **
*/
void			zero_int(t_info *info, va_list args);
void			print_width_int(t_info *info, va_list args);
void			width_point_int(t_info *info, va_list args);
void			nega_width_int(t_info *info, va_list args);

/*
** ft_string.c functions **
*/
void			print_string(t_info *info, va_list args);
void			nega_point_string(t_info *info, va_list args);
void			nega_string(t_info *info, va_list args);
void			point_string(t_info *info, va_list args);
void			print_width_string(t_info *info, va_list args);

/*
** ft_string2.c functions **
*/
void			print_width_string(t_info *info, va_list args);
void			width_point_string(t_info *info, va_list args);
void			nega_width_string(t_info *info, va_list args);

/*
** ft_char.c functions **
*/
void			print_char(t_info *info, va_list args);
void			negative_char(t_info *info, va_list args);
void			point_char(t_info *info, va_list args);
void			print_width_char(t_info *info, va_list args);
void			width_char(t_info *info, va_list args);

/*
** ft_unsigend.c functions **
*/
void			print_unsigned(t_info *info, va_list args);
void			nega_point_unsigned(t_info *info, va_list args);
void			nega_unsigned(t_info *info, va_list args);
void			point_unsigned(t_info *info, va_list args);
void			zero_point_unsigned(t_info *info, va_list args);

/*
** ft_unsigend2.c functions **
*/
void			display_zero_unsigned(t_info *info, va_list args);
void			print_width_unsigned(t_info *info, va_list args);
void			width_point_unsigned(t_info *info, va_list args);

/*
** display_flag.c functions **
*/
void			display_width(t_info *info, va_list args);
void			width_point(t_info *info, va_list args);
void			nega_width_point(t_info *info, va_list args);
void			display_flag_width(t_info *info, va_list args);
void			display_flag_point(t_info *info, va_list args);

/*
** display_flag2.c functions **
*/
void			flag_zero_point(t_info *info, va_list args);
void			display_zero(t_info *info, va_list args);
void			display_flag_zero(t_info *info, va_list args);
void			negative_point(t_info *info, va_list args);
void			display_negative(t_info *info, va_list args);

/*
** display_flag3.c functions **
*/
void			display_flag_negative(t_info *info, va_list args);

/*
** ft_adress.c functions **
*/
void			convert_hex(unsigned long nb, t_info *info);
void			print_adress(va_list args, t_info *info);
void			negative_adress(va_list args, t_info *info);
void			point_negative_adress(va_list args, t_info *info);
void			point_adress(t_info *info, va_list args);

/*
** ft_adress2.c functions **
*/
void			print_width_adress(t_info *info, va_list args);
void			width_point_adress(va_list args, t_info *info);

/*
** ft_hexlow.c functions **
*/
void			print_hex_low(unsigned int nb, t_info *info);
void			print_hex_low2(unsigned int nb);
void			nega_point_hex_low(unsigned int number, t_info *info);
void			nega_hex_low(unsigned int number, t_info *info);
void			point_hex_low(unsigned int number, t_info *info);

/*
** ft_hexlow2.c functions **
*/
void			zero_point_hex_low(unsigned int nb, t_info *info);
void			display_zero_hex_low(t_info *info, va_list args);
void			print_width_hex_low(t_info *info, va_list args);
void			width_point_hex_low(unsigned int number, t_info *info);

/*
** ft_hexup.c functions **
*/
void			print_hex_up(unsigned int nb, t_info *info);
void			print_hex_up2(unsigned int nb);
void			nega_hex_up(unsigned int number, t_info *info);
void			nega_point_hex_up(unsigned int number, t_info *info);
void			point_hex_up(unsigned int number, t_info *info);

/*
** ft_hexup2.c functions **
*/
void			zero_point_hex_up(unsigned int nb, t_info *info);
void			display_zero_hex_up(t_info *info, va_list args);
void			print_width_hex_up(t_info *info, va_list args);
void			width_point_hex_up(unsigned int number, t_info *info);

/*
** help_func.c functions **
*/
void			print_int_zero(t_info *info, int nb, int length);
void			zero_help_func(t_info *info, unsigned int nb, int length);
void			skip_next_negawidth(t_info *info, int length);
#endif
