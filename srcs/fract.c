/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:24:51 by ashari            #+#    #+#             */
/*   Updated: 2019/05/22 14:55:54 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		count_fract(int sign, int exp, char *pow_five, t_wholenumb *n)
{
	int		iter;
	int		i;

	i = 0;
	if (sign)
		iter = 64 - exp - 1;
	else
	{
		iter = 64;
		while (i++ < exp - 1)
			mult(n->fract, 10, &(n->fr_size));
		power(5, exp - 1, pow_five, &(n->fr_size));
	}
	return (iter);
}

char			*work_fract(unsigned int exp, t_wholenumb *n,
							t_flist *flist, int sign)
{
	char			pow_five[STACK_SIZE];
	int				iter;
	unsigned long	mask;

	ft_bzero(pow_five, STACK_SIZE);
	pow_five[0] = 1;
	n->fract[0] = 1;
	iter = count_fract(sign, exp, pow_five, n);
	mask = FIRST_BIT_M;
	while (iter-- >= 0)
	{
		mult(pow_five, 5, &(n->fr_size));
		mult(n->fract, 10, &(n->fr_size));
		if (n->fr_b & mask)
			addit(n->fract, pow_five);
		mask >>= 1u;
	}
	apply_pres_f(flist->precision, n->fract, n->whole);
	return (n->fract);
}
