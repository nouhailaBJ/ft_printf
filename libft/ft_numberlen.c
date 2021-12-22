/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:11:35 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 17:11:44 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numberlen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		i++;
	if (number < 0)
		i++;
	while (number != 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}
