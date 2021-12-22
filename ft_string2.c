/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:50:55 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 18:51:14 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** display string  flag number with . and width > 0 **
*/

void	width_point_string(t_info *info, va_list args)
{
	char	*str;
	int		i;
	int		length;
	int		isnull;

	length = 0;
	i = 0;
	str = va_arg(args, char*);
	isnull = str == NULL ? 1 : 0;
	if (!str)
		str = ft_strdup("(null)");
	while (length < info->pressesion && str[length])
		length++;
	if (info->pressesion < -1)
		length = ft_strlen(str);
	print_space(info, length);
	while (i < length && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	info->count += i;
	(info->i)++;
	if (isnull)
		free_str(str);
}

/*
** display string  flag number with . and width < 0 **
*/

void	nega_width_string(t_info *info, va_list args)
{
	char	*str;
	int		length;
	int		isnull;

	length = 0;
	str = va_arg(args, char*);
	isnull = str == NULL ? 1 : 0;
	str == NULL ? str = ft_strdup("(null)") : 0;
	if (info->pressesion < -1)
	{
		ft_putstr(str);
		length += ft_strlen(str);
	}
	else
	{
		while (length < info->pressesion && str[length])
		{
			ft_putchar(str[length]);
			length++;
		}
	}
	skip_next_negawidth(info, length);
	print_space(info, length);
	isnull == 1 ? free_str(str) : 0;
}
