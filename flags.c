/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:25:23 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 18:25:28 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag - (calcul width - pressesion - and found other flag) **
*/

void	flag_negative(t_info *info, va_list args)
{
	while (info->str[info->i] == '-')
		(info->i)++;
	info->flags[0] = '-';
	info->negative = 1;
	if (info->str[info->i] == '*')
	{
		info->width = va_arg(args, int);
		(info->i)++;
	}
	else
		info->width = calcul_width(info);
	if (info->str[info->i] == '.')
	{
		info->flags[1] = '.';
		(info->i)++;
		if (info->str[info->i] == '*')
		{
			info->pressesion = va_arg(args, int);
			(info->i)++;
		}
		else if (info->str[info->i] >= '0' && info->str[info->i] <= '9')
			info->pressesion = calcul_pressesion(info);
		else
			info->pressesion = 0;
	}
}

/*
** flag 0(calcul width - pressesion - and found other flag) **
*/

void	flag_zero(t_info *info, va_list args)
{
	(info->i)++;
	info->flags[0] = '0';
	if (info->str[info->i] == '*')
	{
		info->width = va_arg(args, int);
		(info->i)++;
	}
	else
		info->width = calcul_width(info);
	if (info->str[info->i] == '.')
	{
		info->flags[1] = '.';
		(info->i)++;
		if (info->str[info->i] == '*')
		{
			info->pressesion = va_arg(args, int);
			(info->i)++;
		}
		else if (info->str[info->i] >= '0' && info->str[info->i] <= '9')
			info->pressesion = calcul_pressesion(info);
		else
			info->pressesion = 0;
	}
}

/*
** flag * (calcul width - pressesion - and found other flag) **
*/

void	flag_star(t_info *info, va_list args)
{
	(info->i)++;
	info->flags[0] = '*';
	info->width = va_arg(args, int);
	if (info->str[info->i] == '.')
	{
		info->flags[1] = '.';
		(info->i)++;
		if (info->str[info->i] == '*')
		{
			info->pressesion = va_arg(args, int);
			(info->i)++;
		}
		else if (info->str[info->i] >= '0' && info->str[info->i] <= '9')
			info->pressesion = calcul_pressesion(info);
		else
			info->pressesion = 0;
	}
}

/*
** flag 0-9 (calcul width - pressesion - and found other flag) **
*/

void	flag_width(t_info *info, va_list args)
{
	info->flags[0] = 'n';
	info->width = calcul_width(info);
	if (info->str[info->i] == '.')
	{
		info->flags[1] = '.';
		(info->i)++;
		if (info->str[info->i] == '*')
		{
			info->pressesion = va_arg(args, int);
			(info->i)++;
		}
		else if (info->str[info->i] >= '0' && info->str[info->i] <= '9')
			info->pressesion = calcul_pressesion(info);
		else
			info->pressesion = 0;
	}
}

/*
** flag . (calcul pressesion ) **
*/

void	flag_point(t_info *info, va_list args)
{
	(info->i)++;
	info->flags[0] = '.';
	if (info->str[info->i] == '*')
	{
		info->pressesion = va_arg(args, int);
		(info->i)++;
	}
	else
		info->pressesion = calcul_pressesion(info);
}
