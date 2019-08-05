/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:21:23 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 05:10:57 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*mult(char *a, int b, int *size)
{
	int		i;

	i = 0;
	while (i < ARR_SIZE && i <= (*size))
		a[i++] *= b;
	i = 0;
	while (i <= ARR_SIZE && i <= (*size))
	{
		if (a[i] >= BASE)
		{
			a[i + 1] += a[i] / BASE;
			a[i] %= BASE;
			(*size)++;
		}
		i++;
	}
	(*size) = i;
	return (a);
}
