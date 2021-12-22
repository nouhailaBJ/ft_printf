/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:57:47 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 17:57:52 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** display int with only flag 0 and . and width > 0 **
*/

void	zero_int(t_info *info, va_list args)
{
	int number;
	int tmp;
	int length;
	int sign;

	tmp = 0;
	number = va_arg(args, int);
	length = nb_point_count(number);
	sign = number < 0 ? 1 : 0;
	tmp = info->pressesion > length ? info->pressesion : length;
	sign == 1 ? tmp++ : 0;
	info->pressesion > 0 ? print_space(info, tmp) : 0;
	sign == 1 ? length++ : 0;
	if (sign == 1 && number != -2147483648)
	{
		number = -number;
		ft_putchar('-');
	}
	if (info->pressesion > 0)
		print_zero(info, info->pressesion - length);
	else
		print_zero(info, info->width - length);
	ft_putnbr(number);
	info->count += length;
	(info->i)++;
}

/*
** display int with flag * or number without flag **
*/

void	print_width_int(t_info *info, va_list args)
{
	int number;

	number = va_arg(args, int);
	if (info->width > 0)
		print_space(info, ft_numberlen(number));
	ft_putnbr(number);
	if (info->width < 0)
	{
		info->width *= -1;
		print_space(info, ft_numberlen(number));
	}
	info->count += ft_numberlen(number);
	(info->i)++;
}

/*
** display int with flag * or number with . flag **
*/

void	width_point_int(t_info *info, va_list args)
{
	int nb;
	int length;
	int space;
	int sign;

	nb = va_arg(args, int);
	length = nb_point_count(nb);
	sign = nb < 0 ? 1 : 0;
	space = info->pressesion > length ? info->pressesion : length;
	sign == 1 ? space++ : 0;
	print_space(info, space);
	sign == 1 ? (info->count)++ : 0;
	if (sign == 1 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (info->pressesion > length)
		print_zero(info, info->pressesion - length);
	if (info->width == 0 && nb == 0 && info->pressesion == 0)
		info->count--;
	else
		nb == 0 && info->pressesion == 0 ? ft_putchar(' ') : ft_putnbr(nb);
	info->count += length;
	(info->i)++;
}

/*
** display int with flag * or number with . flag and nega width **
*/

void	nega_width_int(t_info *info, va_list args)
{
	int nb;
	int tmp;
	int length;
	int sign;

	nb = va_arg(args, int);
	length = nb_point_count(nb);
	sign = nb < 0 ? 1 : 0;
	tmp = info->pressesion > length ? info->pressesion : length;
	if (sign == 1 && nb != -2147483648)
	{
		nb = (-1) * nb;
		ft_putchar('-');
	}
	print_zero(info, tmp - length);
	if (info->width == 0 && nb == 0 && info->pressesion == 0)
		info->count--;
	else
		nb == 0 && info->pressesion == 0 ? ft_putchar(' ') : ft_putnbr(nb);
	info->count += length;
	info->width < 0 ? info->width = info->width * (-1) : 0;
	sign == 1 ? tmp++ : 0;
	sign == 1 ? info->count++ : 0;
	print_space(info, tmp);
	(info->i)++;
}
