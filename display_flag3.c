/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:23:56 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 00:23:58 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_flag_negative(t_info *info, va_list args)
{
	if (info->str[info->i] == '%')
		print_negative_module(info);
	else
	{
		if (info->flags[1] == '.')
			negative_point(info, args);
		else
			display_negative(info, args);
	}
}
