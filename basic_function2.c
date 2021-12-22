/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:04:36 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 00:04:38 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero_module(t_info *info)
{
	if (info->width >= 0)
	{
		print_zero(info, info->width - 1);
		ft_putchar('%');
	}
	else
	{
		info->width *= -1;
		ft_putchar('%');
		print_space(info, 1);
	}
	(info->count)++;
	(info->i)++;
}

void	print_negative_module(t_info *info)
{
	ft_putchar('%');
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, 1);
	(info->count)++;
	(info->i)++;
}

void	print_width_module(t_info *info)
{
	if (info->width > 0 && info->negative != 1)
		print_space(info, 1);
	ft_putchar('%');
	if (info->negative == 1 || info->width < 0)
	{
		info->width *= -1;
		print_space(info, 1);
	}
	(info->count)++;
	(info->i)++;
}

void	print_zero(t_info *info, int tmp)
{
	while (tmp > 0)
	{
		ft_putchar('0');
		(info->count)++;
		tmp--;
	}
}

void	print_space(t_info *info, int tmp)
{
	int	space;

	space = info->width - tmp;
	while (space > 0)
	{
		ft_putchar(' ');
		(info->count)++;
		space--;
	}
}
