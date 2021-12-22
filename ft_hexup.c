/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:25:06 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 20:25:08 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print hex int X **
*/

void	print_hex_up(unsigned int nb, t_info *info)
{
	int		tmp;
	int		j;
	char	*str;

	j = ft_hex_len(nb);
	info->count += j;
	str = (char*)malloc(sizeof(char) * j);
	tmp = 0;
	str[j--] = '\0';
	if (nb == 0)
		str[j--] = '0';
	while (nb != 0)
	{
		tmp = nb % 16;
		if (tmp < 10)
			str[j] = tmp + '0';
		else
			str[j] = tmp + 55;
		j--;
		nb = nb / 16;
	}
	ft_putstr(str);
	(info->i)++;
	free(str);
}

void	print_hex_up2(unsigned int nb)
{
	int		tmp;
	int		j;
	char	*str;

	j = ft_hex_len(nb);
	str = (char*)malloc(sizeof(char) * j);
	tmp = 0;
	str[j--] = '\0';
	if (nb == 0)
		str[j--] = '0';
	while (nb != 0)
	{
		tmp = nb % 16;
		if (tmp < 10)
			str[j] = tmp + '0';
		else
			str[j] = tmp + 55;
		j--;
		nb = nb / 16;
	}
	ft_putstr(str);
	free(str);
}

/*
** print hex int X with flag - and . **
*/

void	nega_hex_up(unsigned int number, t_info *info)
{
	int tmp;
	int length;

	tmp = 0;
	length = ft_hex_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	print_hex_up(number, info);
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, tmp);
}

/*
** print hex int X with flag -  **
*/

void	nega_point_hex_up(unsigned int number, t_info *info)
{
	int tmp;
	int length;

	tmp = 0;
	length = ft_hex_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	if (info->width == 0 && number == 0 && info->pressesion == 0)
		info->i++;
	else if (number == 0 && info->pressesion == 0)
	{
		ft_putchar(' ');
		info->i++;
		info->count++;
	}
	else
		print_hex_up(number, info);
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, tmp);
}

/*
** print hex int X with flag . **
*/

void	point_hex_up(unsigned int number, t_info *info)
{
	int tmp;
	int length;

	tmp = 0;
	length = ft_hex_len(number);
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	if (number == 0 && info->pressesion == 0)
		(info->i)++;
	else
		print_hex_up(number, info);
}
