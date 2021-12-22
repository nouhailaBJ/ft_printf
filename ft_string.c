/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:38:16 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 18:38:17 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** display string with just conv s **
*/

void	print_string(t_info *info, va_list args)
{
	char	*str;
	int		isnull;

	isnull = 0;
	str = va_arg(args, char*);
	if (!str)
	{
		isnull = 1;
		str = ft_strdup("(null)");
	}
	ft_putstr(str);
	info->count += ft_strlen(str);
	(info->i)++;
	if (isnull == 1)
		free_str(str);
}

/*
** display string flag - with . **
*/

void	nega_point_string(t_info *info, va_list args)
{
	char	*str;
	int		len;
	int		isnull;

	str = va_arg(args, char*);
	isnull = str == NULL ? 1 : 0;
	str == NULL ? str = ft_strdup("(null)") : 0;
	len = 0;
	if (info->pressesion < -1)
	{
		ft_putstr(str);
		len += ft_strlen(str);
	}
	else
	{
		while (len < info->pressesion && str[len] && info->pressesion != 0)
		{
			ft_putchar(str[len]);
			len++;
		}
	}
	skip_next_negawidth(info, len);
	print_space(info, len);
	if (isnull)
		free_str(str);
}

/*
** display string flag - without flag **
*/

void	nega_string(t_info *info, va_list args)
{
	char	*str;
	int		isnull;

	str = va_arg(args, char*);
	isnull = str == NULL ? 1 : 0;
	if (!str)
		str = ft_strdup("(null)");
	ft_putstr(str);
	info->count += ft_strlen(str);
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, ft_strlen(str));
	(info->i)++;
	if (isnull)
		free_str(str);
}

/*
** display string only flag .  **
*/

void	point_string(t_info *info, va_list args)
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
	while (i < info->pressesion && str[i])
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
** display string only flag number 0 - 9  **
*/

void	print_width_string(t_info *info, va_list args)
{
	char	*str;
	int		isnull;

	str = va_arg(args, char*);
	isnull = str == NULL ? 1 : 0;
	if (!str)
		str = ft_strdup("(null)");
	if (info->width > 0)
		print_space(info, ft_strlen(str));
	ft_putstr(str);
	info->count += ft_strlen(str);
	(info->i)++;
	if (info->width < 0)
	{
		info->width *= -1;
		print_space(info, ft_strlen(str));
	}
	if (isnull)
		free_str(str);
}
