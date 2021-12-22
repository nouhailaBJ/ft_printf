/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:09:12 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 00:09:15 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_width(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		print_width_int(info, args);
	else if (info->str[info->i] == 's')
		print_width_string(info, args);
	else if (info->str[info->i] == 'c')
		print_width_char(info, args);
	else if (info->str[info->i] == 'u')
		print_width_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		print_width_hex_low(info, args);
	else if (info->str[info->i] == 'X')
		print_width_hex_up(info, args);
	else if (info->str[info->i] == 'p')
		print_width_adress(info, args);
}

void	width_point(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		width_point_int(info, args);
	else if (info->str[info->i] == 's')
		width_point_string(info, args);
	else if (info->str[info->i] == 'c')
		width_char(info, args);
	else if (info->str[info->i] == 'u')
		width_point_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		width_point_hex_low((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'X')
		width_point_hex_up((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'p')
		width_point_adress(args, info);
}

void	nega_width_point(t_info *info, va_list args)
{
	if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
		nega_width_int(info, args);
	else if (info->str[info->i] == 's')
		nega_width_string(info, args);
	else if (info->str[info->i] == 'c')
		negative_char(info, args);
	else if (info->str[info->i] == 'u')
		nega_point_unsigned(info, args);
	else if (info->str[info->i] == 'x')
		nega_point_hex_low((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'X')
		nega_point_hex_up((unsigned int)va_arg(args, int), info);
	else if (info->str[info->i] == 'p')
		negative_adress(args, info);
}

void	display_flag_width(t_info *info, va_list args)
{
	if (info->str[info->i] == '%')
		print_width_module(info);
	else
	{
		if (info->flags[1] == '.')
		{
			if (info->width >= 0)
				width_point(info, args);
			else
				nega_width_point(info, args);
		}
		else
			display_width(info, args);
	}
}

void	display_flag_point(t_info *info, va_list args)
{
	info->str[info->i] == '%' ? print_width_module(info) : 0;
	if (info->pressesion >= 0)
	{
		if (info->str[info->i] == 'd' || info->str[info->i] == 'i')
			point_int(info, args);
		else if (info->str[info->i] == 's')
			point_string(info, args);
		else if (info->str[info->i] == 'c')
			point_char(info, args);
		else if (info->str[info->i] == 'u')
			point_unsigned(info, args);
		else if (info->str[info->i] == 'x')
			point_hex_low((unsigned int)va_arg(args, int), info);
		else if (info->str[info->i] == 'X')
			point_hex_up((unsigned int)va_arg(args, int), info);
		else if (info->str[info->i] == 'p')
			point_adress(info, args);
	}
	else
		find_conversion(info, args);
}
