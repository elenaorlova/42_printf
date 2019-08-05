/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specific_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:06:13 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:06:15 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	apply_format_int(t_flist *flist, va_list *valist)
{
	long long arg;

	if (flist->type == 'D')
	{
		flist->type = 'd';
		free(flist->length);
		flist->length = ft_strdup("l");
	}
	arg = apply_length(flist, valist);
	flist->output = ft_itoa_long(arg);
}

void	apply_format_uns(t_flist *flist, va_list *valist)
{
	unsigned long int arg;

	if (flist->type == 'U')
	{
		flist->type = 'u';
		free(flist->length);
		flist->length = ft_strdup("l");
	}
	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
	arg = apply_length_uns(flist, valist);
	flist->output = ft_itoa_uns(arg);
}

void	apply_format_str(t_flist *flist, va_list *valist)
{
	char *tmp;

	tmp = va_arg(*valist, char*);
	flist->output = ft_strdup(tmp ? tmp : "(null)");
	apply_precision_str(flist);
	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
}

void	apply_format_float(t_flist *flist, va_list *valist)
{
	long double arg;

	if (ft_strequ(flist->length, "L"))
		arg = va_arg(*valist, long double);
	else
		arg = va_arg(*valist, double);
	flist->output = print_float(arg, flist);
}

void	apply_format_percent(t_flist *flist)
{
	flist->output = ft_strdup("%");
	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
	flist->precision = -1;
}
