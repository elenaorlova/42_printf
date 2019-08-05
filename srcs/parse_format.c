/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:52:38 by ashari            #+#    #+#             */
/*   Updated: 2019/05/20 20:52:39 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	get_width(char *str)
{
	int res;

	res = -1;
	if (ft_isdigit(*str))
		res = 0;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (res);
}

static int	get_precision(char *format)
{
	char *dotptr;

	if (!(dotptr = ft_strchr(format, '.')))
		return (-1);
	return (ft_atoi(dotptr + 1));
}

static char	*get_length(char *format)
{
	if (ft_strstr(format, "ll"))
		return (ft_strdup("ll"));
	else if (ft_strstr(format, "l") || ft_strstr(format, "j")
									|| ft_strstr(format, "z"))
		return (ft_strdup("l"));
	else if (ft_strstr(format, "L"))
		return (ft_strdup("L"));
	else if (ft_strstr(format, "hh"))
		return (ft_strdup("hh"));
	else if (ft_strstr(format, "h"))
		return (ft_strdup("h"));
	else
		return (NULL);
}

void		parse_formats(t_flist *flist)
{
	int			i;
	static char *flags = "0+- #";

	while (flist)
	{
		i = 1;
		if (flist->format)
		{
			while (ft_strchr(flags, flist->format[i]))
				ft_strpushchar(&flist->flags, flist->format[i++]);
			flist->width = get_width(flist->format + i);
			flist->precision = get_precision(flist->format);
			flist->length = get_length(flist->format);
			while (flist->format[i])
				i++;
			flist->type = flist->format[i - 1];
		}
		flist = flist->next;
	}
}
