/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:06:02 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:06:04 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	apply_precision_str(t_flist *flist)
{
	size_t prec;

	prec = (flist->precision < 0) ? ft_strlen(flist->output) : flist->precision;
	if (prec < ft_strlen(flist->output))
		flist->output[prec] = 0;
}

void	apply_flags_fix(t_flist *flist)
{
	if ((ft_strequ(flist->output, "0") && (flist->type != 'o') &&
		(flist->type != 'O')) ||
		(flist->precision > 0 && ft_strequ(flist->output, "0")))
		flist->flags = ft_str_removechar(flist->flags, '#');
	if (flist->precision >= 0 && (flist->type != 'f' && flist->type != 's'))
		flist->flags = ft_str_removechar(flist->flags, '0');
	if (flist->precision == 0 && ft_strequ(flist->output, "0") &&
		flist->type != 'f')
	{
		free(flist->output);
		flist->output = ft_strdup("");
		if (flist->type != 'o' && flist->type != 'O')
			flist->flags = ft_str_removechar(flist->flags, '#');
		return ;
	}
}

void	apply_precision(t_flist *flist)
{
	int is_signed;

	apply_flags_fix(flist);
	if (flist->type == 'd' || flist->type == 'i' || flist->type == 'u')
	{
		is_signed = flist->output[0] == '-' ? 1 : 0;
		flist->output = ft_strinsert(flist->output,
				ft_str_generate(flist->precision - ft_strlen(flist->output)
				+ is_signed, '0'), is_signed);
	}
	else if (flist->type == 's')
		apply_precision_str(flist);
	else if (flist->type == 'x' || flist->type == 'o' || flist->type == 'O'
						|| flist->type == 'X' || flist->type == 'p')
		flist->output = ft_strinsert(flist->output,
				ft_str_generate(flist->precision - ft_strlen(flist->output)
				- (ft_strchr(flist->flags, '#') &&
				flist->type == 'o' ? 1 : 0), '0'), 0);
}
