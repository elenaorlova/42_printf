/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:56:15 by ashari            #+#    #+#             */
/*   Updated: 2019/05/22 15:39:39 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** 		Usage: printf("%b", number);
*/

char	*ft_print_bits(size_t size, void const *ptr)
{
	unsigned char	*b;
	int				i;
	int				j;
	int				iter;
	char			*res;

	b = (unsigned char *)ptr;
	i = size - 1;
	iter = 0;
	res = ft_strnew(100);
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			res[iter++] = (((b[i] >> j) & 1u) != 0) ? '1' : '0';
			j--;
		}
		res[iter++] = ' ';
		i--;
	}
	return (res);
}
