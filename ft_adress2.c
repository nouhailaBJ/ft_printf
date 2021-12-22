/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:02:35 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 00:02:38 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_adress(t_info *info, va_list args)
{
	unsigned long number;

	number = (unsigned long)va_arg(args, void*);
	if (info->width > 0)
		print_space(info, ft_long_len(number) + 2);
	ft_putstr("0x");
	info->count += 2;
	convert_hex(number, info);
	if (info->width < 0)
	{
		info->width *= -1;
		print_space(info, ft_long_len(number) + 2);
	}
}

void	width_point_adress(va_list args, t_info *info)
{
	unsigned long	number;
	int				length;
	int				space;

	space = 0;
	number = (unsigned long)va_arg(args, int);
	length = ft_long_len(number) + 2;
	if (info->pressesion > length)
		space = info->pressesion;
	else if (number == 0 && info->pressesion == 0)
		space = 2;
	else
		space = length;
	print_space(info, space);
	ft_putstr("0x");
	info->count += 2;
	if (number == 0 && info->pressesion == 0)
		(info->i)++;
	else
		convert_hex(number, info);
}
