/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:11:04 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 17:11:28 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_long_len(unsigned long number)
{
	int i;

	i = 0;
	if (number == 0)
		i++;
	while (number != 0)
	{
		i++;
		number = number / 16;
	}
	return (i);
}
