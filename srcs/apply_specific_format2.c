/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specific_format2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:22:36 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:22:37 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	apply_format_char(t_flist *flist, va_list *valist)
{
	char *c;

	if (flist->type == 'C')
	{
		flist->type = 'c';
		free(flist->length);
		flist->length = ft_strdup("l");
	}
	flist->precision = -1;
	c = ft_strnew(2);
	c[0] = va_arg(*valist, int);
	flist->flags = ft_str_removechar(flist->flags, ' ');
	if (c[0] == 0)
	{
		c[0] = -1;
		flist->flags = ft_str_removechar(flist->flags, '+');
	}
	flist->output = c;
}

void	apply_format_oct(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	if (flist->type == 'O')
	{
		flist->type = 'o';
		free(flist->length);
		flist->length = ft_strdup("l");
	}
	arg = apply_length_uns(flist, valist);
	flist->output = ft_itoa_base(arg, 8, 0);
	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
}

void	apply_format_hex(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(flist, valist);
	flist->output = (flist->type == 'x') ? ft_itoa_base(arg, 16, 0)
			: ft_itoa_base(arg, 16, 1);
	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
}

void	apply_format_ptr(t_flist *flist, va_list *valist)
{
	long int arg;

	arg = va_arg(*valist, long int);
	flist->output = ft_itoa_base(arg, 16, 0);
	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
	ft_strpushchar(&flist->flags, '#');
}

void	apply_format_byte(t_flist *flist, va_list *valist)
{
	long long arg;

	arg = apply_length(flist, valist);
	ft_bzero(flist->flags, ft_strlen(flist->flags));
	flist->precision = -1;
	if (ft_strequ(flist->length, "ll"))
		flist->output = ft_print_bits(sizeof(long long), &arg);
	else if (ft_strequ(flist->length, "l"))
		flist->output = ft_print_bits(sizeof(long), &arg);
	else if (ft_strequ(flist->length, "hh"))
		flist->output = ft_print_bits(sizeof(char), &arg);
	else if (ft_strequ(flist->length, "h"))
		flist->output = ft_print_bits(sizeof(short), &arg);
	else
		flist->output = ft_print_bits(sizeof(int), &arg);
}
