/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:28:12 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 17:28:14 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** display int with just conv d **
*/

void	print_int(t_info *info, va_list args)
{
	int number;

	number = va_arg(args, int);
	ft_putnbr(number);
	info->count += ft_numberlen(number);
	(info->i)++;
}

/*
** display int with flag - and . **
*/

void	nega_point_int(t_info *info, va_list args)
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
	print_int_zero(info, nb, length);
	if (info->width < 0)
		info->width = info->width * (-1);
	sign == 1 ? tmp++ : 0;
	sign == 1 ? info->count++ : 0;
	print_space(info, tmp);
}

/*
** display int with flag - **
*/

void	nega_int(t_info *info, va_list args)
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
	if (sign == 1 && number != -2147483648)
	{
		number = (-1) * number;
		ft_putchar('-');
	}
	print_zero(info, tmp - length);
	ft_putnbr(number);
	info->count += length;
	if (info->width < 0)
		info->width = info->width * (-1);
	sign == 1 ? tmp++ : 0;
	sign == 1 ? info->count++ : 0;
	print_space(info, tmp);
	(info->i)++;
}

/*
** display int with only flag . **
*/

void	point_int(t_info *info, va_list args)
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
	if (sign == 1 && number != -2147483648)
	{
		number = -number;
		ft_putchar('-');
	}
	if (sign == 1)
		info->count += 1;
	print_zero(info, info->pressesion - length);
	if (number == 0 && info->pressesion == 0)
		(info->count)--;
	else
		ft_putnbr(number);
	info->count += length;
	(info->i)++;
}

/*
** display int with only flag 0 and . and width > 0 **
*/

void	zero_point_int(t_info *info, va_list args)
{
	int nb;
	int tmp;
	int length;
	int sign;

	nb = va_arg(args, int);
	length = nb_point_count(nb);
	sign = nb < 0 ? 1 : 0;
	tmp = info->pressesion > length ? info->pressesion : length;
	sign == 1 ? tmp++ : 0;
	info->pressesion >= 0 ? print_space(info, tmp) : 0;
	if (sign == 1 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
		if (info->pressesion < 0)
			length++;
	}
	if (info->pressesion > 0)
		print_zero(info, info->pressesion - length);
	else if (info->pressesion != 0)
		print_zero(info, info->width - length);
	sign == 1 && info->pressesion >= 0 ? length++ : 0;
	print_int_zero(info, nb, length);
}
