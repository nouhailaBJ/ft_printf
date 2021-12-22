/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:00:38 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 20:00:48 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print unsigned int with flag 0  **
*/

void	display_zero_unsigned(t_info *info, va_list args)
{
	unsigned int number;

	number = (unsigned int)va_arg(args, int);
	if (info->width > 0)
		print_zero(info, info->width - ft_unsigned_len(number));
	ft_putnbr_uns(number);
	info->count += ft_unsigned_len(number);
	(info->i)++;
}

/*
** print unsigned int with flag width  **
*/

void	print_width_unsigned(t_info *info, va_list args)
{
	unsigned int	number;

	number = va_arg(args, int);
	if (info->width > 0)
		print_space(info, ft_unsigned_len(number));
	ft_putnbr_uns(number);
	if (info->width < 0)
	{
		info->width *= -1;
		print_space(info, ft_unsigned_len(number));
	}
	info->count += ft_unsigned_len(number);
	(info->i)++;
}

/*
** print unsigned int with flag width  and flag .**
*/

void	width_point_unsigned(t_info *info, va_list args)
{
	unsigned int	number;
	int				length;
	int				space;

	space = 0;
	number = (unsigned int)va_arg(args, int);
	length = ft_unsigned_len(number);
	if (info->pressesion > length)
		space = info->pressesion;
	else
		space = length;
	print_space(info, space);
	print_zero(info, space - length);
	if (info->width == 0 && number == 0 && info->pressesion == 0)
		info->count--;
	else if (number == 0 && info->pressesion == 0)
		ft_putchar(' ');
	else
		ft_putnbr_uns(number);
	info->count += length;
	(info->i)++;
}
