/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:51:05 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 16:11:25 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** initialisation les variable de structure **
*/

void	initialisation(t_info *info)
{
	info->i = 0;
	info->width = 0;
	info->pressesion = -1;
	info->negative = 0;
	info->count = 0;
}

/*
** reinitialiser les variable de structure a chaque fois **
*/

void	re_initialisation(t_info *info)
{
	info->flags[0] = '\0';
	info->flags[1] = '\0';
	info->width = 0;
	info->pressesion = -1;
	info->negative = 0;
}

/*
** find the conversion and flags and display it **
*/

void	ft_conversion(t_info *info, va_list args)
{
	(info->i)++;
	if (info->str[info->i] == '%')
	{
		ft_putchar('%');
		(info->i)++;
		(info->count)++;
	}
	else
	{
		find_conversion(info, args);
		find_flag(info, args);
		display_str(info, args);
	}
}

/*
** print string or trait the args **
*/

void	basic_printf(t_info *info, va_list args)
{
	while (info->str[info->i] != '\0')
	{
		if (info->str[info->i] == '%')
		{
			re_initialisation(info);
			ft_conversion(info, args);
		}
		else
		{
			ft_putchar(info->str[info->i]);
			(info->count)++;
			(info->i)++;
		}
	}
}

/*
** global function ft_printf **
*/

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_info	info;

	va_start(args, str);
	info.str = str;
	initialisation(&info);
	basic_printf(&info, args);
	return (info.count);
}
