/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:42:44 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 00:02:06 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_hex(unsigned long nb, t_info *info)
{
	int		tmp;
	int		j;
	char	*str;

	j = ft_long_len(nb);
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
			str[j] = tmp + 87;
		j--;
		nb = nb / 16;
	}
	ft_putstr(str);
	(info->i)++;
	free(str);
}

void	print_adress(va_list args, t_info *info)
{
	unsigned long	nb;

	nb = (unsigned long)va_arg(args, void*);
	ft_putstr("0x");
	info->count += 2;
	convert_hex(nb, info);
}

void	negative_adress(va_list args, t_info *info)
{
	unsigned long	number;
	int				tmp;
	int				length;

	tmp = 0;
	number = (unsigned long)va_arg(args, void*);
	length = ft_long_len(number) + 2;
	if (info->pressesion > length)
		tmp = info->pressesion;
	else
		tmp = length;
	print_zero(info, tmp - length);
	ft_putstr("0x");
	info->count += 2;
	if (number == 0 && info->pressesion == 0)
	{
		tmp--;
		(info->i)++;
	}
	else
		convert_hex(number, info);
	if (info->width < 0)
		info->width = info->width * (-1);
	print_space(info, tmp);
}

void	point_negative_adress(va_list args, t_info *info)
{
	unsigned long	number;
	int				tmp;
	int				length;

	tmp = 0;
	number = (unsigned long)va_arg(args, void*);
	length = ft_long_len(number) + 2;
	if (info->pressesion == 0)
	{
		tmp = info->pressesion > length ? info->pressesion : length;
		print_zero(info, tmp - length);
		ft_putstr("0x");
		info->count += 2;
		if (number == 0 && info->pressesion == 0)
		{
			tmp--;
			(info->i)++;
		}
		else
			convert_hex(number, info);
		if (info->width < 0)
			info->width = info->width * (-1);
		print_space(info, tmp);
	}
}

void	point_adress(t_info *info, va_list args)
{
	unsigned long	nb;

	nb = (unsigned long)va_arg(args, void*);
	ft_putstr("0x");
	info->count += 2;
	if (nb == 0 && info->pressesion == 0)
		(info->i)++;
	else
		convert_hex(nb, info);
}
