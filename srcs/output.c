/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:26:41 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:26:43 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_flist(t_flist *flist)
{
	free(flist->format);
	free(flist->output);
	free(flist->length);
	free(flist->flags);
	free(flist);
}

int		printf_output(t_flist *flist)
{
	size_t	res_len;
	t_flist	*tmp;

	res_len = 0;
	while (flist)
	{
		res_len += ft_strlen_safe(flist->output);
		ft_stupid_putstr(flist->output);
		tmp = flist;
		flist = flist->next;
		free_flist(tmp);
	}
	return (res_len);
}
