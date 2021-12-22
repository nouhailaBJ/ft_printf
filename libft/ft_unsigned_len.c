/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:12:52 by nbjaghou          #+#    #+#             */
/*   Updated: 2019/11/22 17:13:01 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsigned_len(unsigned int number)
{
	int i;

	i = 0;
	if (number == 0)
		i++;
	while (number != 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}
