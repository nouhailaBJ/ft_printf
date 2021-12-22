/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:31:45 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 23:31:46 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print hex int x with flag 0 and . **
*/

void	zero_point_hex_low(unsigned int nb, t_info *info)
{
	int tmp;
	int length;

	tmp = 0;
	length = ft_hex_len(nb);
	tmp = info->pressesion > length ? info->pressesion : length;
	if (info->pressesion >= 0)
	{
		info->width > 0 ? print_space(info, tmp) : 0;
		print_zero(info, tmp - length);
	}
	else
		print_zero(info, info->width - length);
	if (info->width == 0 && nb == 0 && info->pressesion == 0)
		info->count--;
	else
		nb == 0 && info->pressesion == 0 ? ft_putchar(' ') : print_hex_low2(nb);
	if (info->width < 0)
	{
		info->width = info->width * (-1);
		print_space(info, tmp);
	}
	info->i++;
	info->count += length;
}

/*
** print hex int x with flag 0  **
*/

void	display_zero_hex_low(t_info *info, va_list args)
{
	unsigned int number;

	number = va_arg(args, int);
	if (info->width > 0)
		print_zero(info, info->width - ft_hex_len(number));
	print_hex_low(number, info);
}

/*
** print hex int x with flag width  **
*/

void	print_width_hex_low(t_info *info, va_list args)
{
	unsigned int number;

	number = va_arg(args, int);
	if (info->width > 0)
		print_space(info, ft_hex_len(number));
	print_hex_low(number, info);
	if (info->width < 0)
	{
		info->width *= -1;
		print_space(info, ft_hex_len(number));
	}
}

/*
** print hex int x with flag width and .  **
*/

void	width_point_hex_low(unsigned int number, t_info *info)
{
	int tmp;
	int length;

	tmp = 0;
	length = ft_hex_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_space(info, tmp);
	print_zero(info, tmp - length);
	if (info->width == 0 && number == 0 && info->pressesion == 0)
		info->i++;
	else if (number == 0 && info->pressesion == 0)
	{
		ft_putchar(' ');
		info->i++;
		info->count++;
	}
	else
		print_hex_low(number, info);
}
