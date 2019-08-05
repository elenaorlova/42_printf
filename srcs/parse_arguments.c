/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:41:40 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 16:41:42 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#define PUSH flist_push
#define CREATE flist_create
#define SUB ft_strsub

t_flist		*parse_input_helper(size_t *i, char *str, t_flist *flist)
{
	int				w_start;
	static char		*types = "cCsSpdDioOuUxX%fb";

	w_start = *i;
	if (str[*i] == '%')
	{
		(*i)++;
		while (str[*i] != 0 && !ft_strchr(types, str[*i]))
			(*i)++;
		PUSH(&flist, CREATE(SUB(str, w_start, *i - w_start + 1), NULL));
	}
	else
	{
		while (str[*i + 1] != '%' && str[*i + 1] != 0)
			(*i)++;
		PUSH(&flist, CREATE(NULL, SUB(str, w_start, *i - w_start + 1)));
	}
	return (flist);
}

t_flist		*parse_input(char *str)
{
	t_flist			*flist;
	size_t			len;
	size_t			i;

	i = -1;
	flist = NULL;
	len = ft_strlen(str);
	while (++i < len)
		flist = parse_input_helper(&i, str, flist);
	return (flist);
}
