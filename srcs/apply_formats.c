/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:05:51 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:05:53 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			apply_prec_flags_width(t_flist *flist)
{
	if (flist->output)
	{
		apply_precision(flist);
		apply_flags(flist);
		apply_width(flist);
	}
}

static void			apply_format_helper(t_flist *flist, va_list *valist)
{
	if (flist->type == 'd' || flist->type == 'i' || flist->type == 'D')
		apply_format_int(flist, valist);
	else if (flist->type == 's' || flist->type == 'S')
		apply_format_str(flist, valist);
	else if (flist->type == 'c' || flist->type == 'C')
		apply_format_char(flist, valist);
	else if (flist->type == 'o' || flist->type == 'O')
		apply_format_oct(flist, valist);
	else if (flist->type == 'x')
		apply_format_hex(flist, valist);
	else if (flist->type == 'X')
		apply_format_hex(flist, valist);
	else if (flist->type == 'f')
		apply_format_float(flist, valist);
	else if (flist->type == 'p')
		apply_format_ptr(flist, valist);
	else if (flist->type == 'u' || flist->type == 'U')
		apply_format_uns(flist, valist);
	else if (flist->type == 'b')
		apply_format_byte(flist, valist);
	else if (flist->type == '%')
		apply_format_percent(flist);
	apply_prec_flags_width(flist);
}

void				apply_formats(t_flist *flist, va_list *valist)
{
	while (flist)
	{
		if (flist->format)
			apply_format_helper(flist, valist);
		flist = flist->next;
	}
}

long long			apply_length(t_flist *flist, va_list *valist)
{
	long long arg;

	arg = va_arg(*valist, long long);
	if (ft_strequ(flist->length, "ll"))
		arg = (long long)arg;
	else if (ft_strequ(flist->length, "l"))
		arg = (long)arg;
	else if (ft_strequ(flist->length, "hh"))
		arg = (char)arg;
	else if (ft_strequ(flist->length, "h"))
		arg = (short)arg;
	else
		arg = (int)arg;
	return (arg);
}

unsigned long long	apply_length_uns(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = va_arg(*valist, unsigned long long);
	if (ft_strequ(flist->length, "ll"))
		arg = (unsigned long long)arg;
	else if (ft_strequ(flist->length, "l"))
		arg = (unsigned long)arg;
	else if (ft_strequ(flist->length, "hh"))
		arg = (unsigned char)arg;
	else if (ft_strequ(flist->length, "h"))
		arg = (unsigned short)arg;
	else
		arg = (unsigned int)arg;
	return (arg);
}
