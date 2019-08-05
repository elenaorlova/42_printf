/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_pres_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:40:01 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 05:13:38 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				add_one_whole(char *whole, int i)
{
	whole[0] += 1;
	while (whole[i] >= BASE && i < (ARR_SIZE - 1))
	{
		whole[i + 1] += whole[i] / BASE;
		whole[i] %= BASE;
		i++;
	}
	return (i);
}

static int				add_one_fract(char *fract, int i, int pres)
{
	fract[++i] += 1;
	while (fract[i] >= BASE && --pres > 0)
	{
		fract[i + 1] += fract[i] / BASE;
		fract[i] %= BASE;
		i++;
	}
	return (i);
}

static int				five_and_numbs(const char *fract, int i)
{
	if (fract[i] != 5)
		return (0);
	i--;
	while (i > 0)
	{
		if (fract[i] == 0)
			i--;
		else
			return (1);
	}
	return (0);
}

void					apply_pres_f(int pres, char *fract, char *whole)
{
	int		i;
	int		tmp_i;
	int		tmp_pres;

	i = ARR_SIZE - 1;
	tmp_pres = pres;
	while (fract[i] == 0 && i > 0)
		i--;
	i--;
	tmp_i = i;
	while (tmp_pres-- && i >= -1)
		i--;
	if (i >= 0 && ((whole[0] % 2 != 0 && fract[i] == 5) || fract[i] > 5
	|| five_and_numbs(fract, tmp_i)) && pres == 0)
		add_one_whole(whole, 0);
	else if (i >= 0 && (fract[i] > 5 || (fract[i + 1] % 2 != 0
	&& fract[i] == 5)))
	{
		add_one_fract(fract, i, pres);
		if (fract[tmp_i] >= BASE)
		{
			fract[tmp_i] %= BASE;
			add_one_whole(whole, 0);
		}
	}
}
