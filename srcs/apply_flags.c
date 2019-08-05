/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:05:39 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/22 14:53:30 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	apply_flag_plus(t_flist *flist)
{
	size_t	nbrlen;
	char	*tmp;

	if (flist->type == 'o' || flist->type == 'O' || flist->type == 'x'
	|| flist->type == 'X' || flist->type == 's' || flist->type == 'S')
		return ;
	nbrlen = ft_strlen(flist->output);
	if (ft_strchr(flist->flags, '0'))
	{
		tmp = ft_strjoin_free("+", ft_str_generate(flist->width - nbrlen - 1,
				'0'), 2);
		flist->output = ft_strjoin_free(tmp, flist->output, 3);
	}
	else
		flist->output = ft_strjoin_free("+", flist->output, 2);
}

static void	apply_flag_minus(t_flist *flist)
{
	int		outlen;
	char	*output;

	outlen = ft_strlen(flist->output);
	output = ft_strdup(flist->output);
	if (flist->width > outlen)
	{
		free(flist->output);
		flist->output = ft_strnew(flist->width);
		ft_strcpy(flist->output, output);
		while (flist->width - outlen)
			flist->output[outlen++] = ' ';
	}
	free(output);
}

void		apply_flag_hash(t_flist *flist)
{
	char *tmp_out;

	tmp_out = ft_strdup(flist->output);
	free(flist->output);
	if (flist->type == 'o' || flist->type == 'O')
		flist->output = ft_strjoin("0", tmp_out);
	else if (flist->type == 'x' || flist->type == 'p')
		flist->output = ft_strjoin("0x", tmp_out);
	else if (flist->type == 'X')
		flist->output = ft_strjoin("0X", tmp_out);
	else
		flist->output = ft_strdup(tmp_out);
	free(tmp_out);
}

void		apply_flags(t_flist *flist)
{
	if (ft_strchr(flist->flags, '-'))
		flist->flags = ft_str_removechar(flist->flags, '0');
	if (flist->precision >= flist->width && flist->type != 's'
	&& flist->type != 'f')
	{
		flist->width = flist->precision;
		flist->flags = ft_str_removechar(flist->flags, '-');
		ft_strpushchar(&flist->flags, '0');
	}
	if (ft_strchr(flist->flags, '+') && flist->output[0] != '-')
		apply_flag_plus(flist);
	else if (ft_strchr(flist->flags, ' ') && flist->output[0] != '-')
		flist->output = ft_strjoin_free(" ", flist->output, 2);
	if ((ft_strchr(flist->flags, '#') && !ft_strequ(flist->output, "0"))
	|| flist->type == 'p')
		apply_flag_hash(flist);
	if (ft_strchr(flist->flags, '-'))
		apply_flag_minus(flist);
}
