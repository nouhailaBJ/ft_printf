/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:17:14 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 00:17:16 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero_point(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		zero_point_int(info, args);
	else if (info->str[info->i] == 'u')
		zero_point_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		zero_point_hex_low((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'X')
		zero_point_hex_up((unsigned int)va_arg(args, int), info);
}

void	display_zero(t_info *info, va_list args)
{
	if (info->width > 0)
	{
		if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
			zero_int(info, args);
		else if (info->str[info->i] == 'u')
			display_zero_unsigned(info, args);
		else if (info->str[info->i] == 'x')
			display_zero_hex_low(info, args);
		else if (info->str[info->i] == 'X')
			display_zero_hex_up(info, args);
		else if (info->str[info->i] == '%')
			print_zero_module(info);
	}
	else
		display_negative(info, args);
}

void	display_flag_zero(t_info *info, va_list args)
{
	if (info->str[info->i] == '%')
		print_zero_module(info);
	else
	{
		if (info->flags[1] == '.')
		{
			if (info->width > 0)
				flag_zero_point(info, args);
			else
				negative_point(info, args);
		}
		else
			display_zero(info, args);
	}
}

void	negative_point(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		nega_point_int(info, args);
	else if (info->str[info->i] == 's')
		nega_point_string(info, args);
	else if (info->str[info->i] == 'c')
		negative_char(info, args);
	else if (info->str[info->i] == 'u')
		nega_point_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		nega_point_hex_low((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'X')
		nega_point_hex_up((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'p')
		point_negative_adress(args, info);
}

void	display_negative(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		nega_int(info, args);
	else if (info->str[info->i] == 's')
		nega_string(info, args);
	else if (info->str[info->i] == 'c')
		negative_char(info, args);
	else if (info->str[info->i] == 'u')
		nega_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		nega_hex_low((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'X')
		nega_hex_up((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'p')
		negative_adress(args, info);
	else if (info->str[info->i] == '%')
		print_width_module(info);
}
