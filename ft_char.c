/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:54:58 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 18:55:01 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** display char c **
*/

void	print_char(t_info *info, va_list args)
{
	ft_putchar(va_arg(args, int));
	(info->count)++;
	(info->i)++;
}

/*
** display char c with flag - **
*/

void	negative_char(t_info *info, va_list args)
{
	char c;

	c = va_arg(args, int);
	ft_putchar(c);
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, 1);
	info->count += 1;
	(info->i)++;
}

/*
** display char c with flag . **
*/

void	point_char(t_info *info, va_list args)
{
	ft_putchar(va_arg(args, int));
	(info->count)++;
	(info->i)++;
}

/*
** display char c with flag width **
*/

void	print_width_char(t_info *info, va_list args)
{
	if (info->width > 0)
		print_space(info, 1);
	ft_putchar(va_arg(args, int));
	info->count += 1;
	(info->i)++;
	if (info->width < 0)
	{
		info->width *= -1;
		print_space(info, 1);
	}
}

/*
** display char c with flag width and .**
*/

void	width_char(t_info *info, va_list args)
{
	char c;

	c = va_arg(args, int);
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, 1);
	ft_putchar(c);
	info->count += 1;
	(info->i)++;
}
