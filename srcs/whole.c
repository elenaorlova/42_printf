/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:25:56 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 05:16:43 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*work_whole(int exp, unsigned long wh_b, char *whole,
							int *wh_size)
{
	char			pow_two[STACK_SIZE];
	int				iter;
	unsigned long	mask;

	mask = 1;
	ft_bzero(pow_two, STACK_SIZE);
	if (wh_b == 0)
	{
		mult(whole, 0, wh_size);
		return (whole);
	}
	pow_two[0] = 1;
	iter = (exp < 63) ? exp + 1 : 64;
	if (exp >= 63)
		power(2, exp - 63, pow_two, wh_size);
	while (iter-- >= 0)
	{
		if (wh_b & mask)
			addit(whole, pow_two);
		mult(pow_two, 2, wh_size);
		mask <<= 1u;
	}
	return (whole);
}
