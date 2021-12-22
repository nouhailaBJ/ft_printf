/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:01:06 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 19:01:09 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print unsigned int only conv u **
*/

void	print_unsigned(t_info *info, va_list args)
{
	unsigned int number;

	number = va_arg(args, int);
	ft_putnbr_uns(number);
	info->count += ft_unsigned_len(number);
	(info->i)++;
}

/*
** print unsigned int with - and . **
*/

void	nega_point_unsigned(t_info *info, va_list args)
{
	unsigned int	number;
	int				tmp;
	int				length;

	tmp = 0;
	number = (unsigned int)va_arg(args, int);
	length = ft_unsigned_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	if (info->width == 0 && number == 0 && info->pressesion == 0)
		info->count--;
	else if (number == 0 && info->pressesion == 0)
		ft_putchar(' ');
	else
		ft_putnbr_uns(number);
	info->count += length;
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, tmp);
	(info->i)++;
}

/*
** print unsigned int with -  **
*/

void	nega_unsigned(t_info *info, va_list args)
{
	unsigned int	number;
	int				tmp;
	int				length;

	tmp = 0;
	number = (unsigned int)va_arg(args, int);
	length = ft_unsigned_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	ft_putnbr_uns(number);
	info->count += length;
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, tmp);
	(info->i)++;
}

/*
** print unsigned int with flag .  **
*/

void	point_unsigned(t_info *info, va_list args)
{
	unsigned int	number;
	int				tmp;
	int				length;

	tmp = 0;
	number = (unsigned int)va_arg(args, int);
	length = ft_unsigned_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	if (number == 0 && info->pressesion == 0)
		(info->count)--;
	else
		ft_putnbr_uns(number);
	info->count += length;
	(info->i)++;
}

/*
** print unsigned int with flag 0 and .  **
*/

void	zero_point_unsigned(t_info *info, va_list args)
{
	unsigned int	nb;
	int				tmp;
	int				length;

	nb = (unsigned int)va_arg(args, int);
	length = ft_unsigned_len(nb);
	tmp = info->pressesion > length ? info->pressesion : length;
	if (info->pressesion >= 0)
	{
		info->width > 0 ? print_space(info, tmp) : 0;
		print_zero(info, tmp - length);
	}
	else
		print_zero(info, info->width - length);
	zero_help_func(info, nb, length);
	if (info->width < 0)
	{
		info->width = info->width * (-1);
		print_space(info, tmp);
	}
}
