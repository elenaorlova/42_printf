/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:39:04 by ashari            #+#    #+#             */
/*   Updated: 2019/05/22 14:54:42 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define TMP_SIZE 100

static int		skip_chars(const char *src, int size)
{
	int		i;

	i = size + 1;
	while (!src[i] && i >= 0)
		i--;
	i--;
	return (i);
}

static char		*parse_fract(t_wholenumb *n, int pres, int j)
{
	int		i;

	while (n->res[j])
		j++;
	n->res[j++] = '.';
	i = skip_chars(n->fract, n->fr_size);
	while (i >= 0 && pres--)
		n->res[j++] = n->fract[i--] + '0';
	while (pres-- > 0)
		n->res[j++] = '0';
	return (n->res);
}

static int		parse_whole(char *res, const char *src, char sign, int wh_size)
{
	int		i;
	int		j;

	i = wh_size - 1;
	j = 0;
	while (!src[i] && i >= 0)
		i--;
	if (sign == '-')
		res[j++] = '-';
	while (i >= 0)
		res[j++] = src[i--] + '0';
	return (j);
}

char			*parse_result(t_wholenumb *n, t_flist *flist)
{
	int		j;

	j = 0;
	flist->precision = (int)ft_abs((int)flist->precision);
	n->res = (flist->precision > n->fr_size) ?
	ft_strnew(flist->precision + n->wh_size)
			: ft_strnew(n->fr_size + n->wh_size);
	if (!n->res)
		return (ft_strnew(1));
	if (n->wh_b == 0)
		n->res = (n->sign == '-') ? ft_strcpy(n->res, "-0") :
		ft_strcpy(n->res, "0");
	else
		j = parse_whole(n->res, n->whole, n->sign, n->wh_size);
	if (flist->precision)
		n->res = parse_fract(n, flist->precision, j);
	else if (!flist->precision && ft_strchr(flist->flags, '#'))
	{
		while (n->res[j])
			j++;
		n->res[j] = '.';
	}
	return (n->res);
}
