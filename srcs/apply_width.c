/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:06:25 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:06:27 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	apply_width(t_flist *flist)
{
	int		shift;
	char	chr;

	if (ft_strchr(flist->flags, '-'))
		return ;
	if (ft_strchr(flist->flags, '0'))
	{
		if (ft_strchr(flist->flags, '#') && (flist->type == 'x'
		|| flist->type == 'X'))
			shift = 2;
		else
			shift = (ft_strchr(flist->output, '-')
				|| ft_strchr(flist->flags, ' ')) ? 1 : 0;
	}
	else
		shift = 0;
	chr = ft_strchr(flist->flags, '0') ? '0' : ' ';
	flist->output = ft_strinsert(flist->output, ft_str_generate(flist->width
	- ft_strlen(flist->output), chr), shift);
}
