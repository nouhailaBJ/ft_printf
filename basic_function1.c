/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:26:30 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 16:52:10 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** calcul width  **
*/

int		calcul_width(t_info *info)
{
	int width;

	width = 0;
	while (info->str[info->i] >= '0' && info->str[info->i] <= '9')
	{
		width = width * 10 + info->str[info->i] - '0';
		(info->i)++;
	}
	return (width);
}

/*
** calcul pressesion  **
*/

int		calcul_pressesion(t_info *info)
{
	int pressesion;

	pressesion = 0;
	while (info->str[info->i] >= '0' && info->str[info->i] <= '9')
	{
		pressesion = pressesion * 10 + info->str[info->i] - '0';
		(info->i)++;
	}
	return (pressesion);
}

/*
** display string with flags **
*/

void	display_str(t_info *info, va_list args)
{
	if (info->flags[0] == '-')
		display_flag_negative(info, args);
	else if (info->flags[0] == '0')
		display_flag_zero(info, args);
	else if (info->flags[0] == 'n' || info->flags[0] == '*')
		display_flag_width(info, args);
	else if (info->flags[0] == '.')
		display_flag_point(info, args);
}

/*
** search convesrion and display normal **
*/

void	find_conversion(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		print_int(info, args);
	else if (info->str[info->i] == 's')
		print_string(info, args);
	else if (info->str[info->i] == 'c')
		print_char(info, args);
	else if (info->str[info->i] == 'u')
		print_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		print_hex_low((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'X')
		print_hex_up((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'p')
		print_adress(args, info);
}

/*
** search flags **
*/

void	find_flag(t_info *info, va_list args)
{
	if (info->str[info->i] == '-')
		flag_negative(info, args);
	else if (info->str[info->i] == '0')
		flag_zero(info, args);
	else if (info->str[info->i] == '*')
		flag_star(info, args);
	else if (info->str[info->i] >= '0' && info->str[info->i] <= '9')
		flag_width(info, args);
	else if (info->str[info->i] == '.')
		flag_point(info, args);
}
