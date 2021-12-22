/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:21:14 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/23 12:21:24 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** function help in norminnete for int **
*/

void	print_int_zero(t_info *info, int nb, int length)
{
	if (info->width == 0 && nb == 0 && info->pressesion == 0)
		info->count--;
	else
		nb == 0 && info->pressesion == 0 ? ft_putchar(' ') : ft_putnbr(nb);
	info->count += length;
	(info->i)++;
}

/*
** function help in norminnete for unsigned int conv : u **
*/

void	zero_help_func(t_info *info, unsigned int nb, int length)
{
	if (info->width == 0 && nb == 0 && info->pressesion == 0)
		info->count--;
	else if (nb == 0 && info->pressesion == 0)
		ft_putchar(' ');
	else
		ft_putnbr_uns(nb);
	info->count += length;
	(info->i)++;
}

void	skip_next_negawidth(t_info *info, int length)
{
	info->count += length;
	(info->i)++;
	if (info->width < 0)
		info->width = info->width * (-1);
}
