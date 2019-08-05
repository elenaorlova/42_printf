/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:07:31 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/21 01:26:34 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>

int		ft_printf(const char *str, ...)
{
	va_list valist;
	t_flist *format_list;

	if (!str)
		return (0);
	va_start(valist, str);
	format_list = parse_input((char*)str);
	parse_formats(format_list);
	apply_formats(format_list, &valist);
	va_end(valist);
	return (printf_output(format_list));
}
