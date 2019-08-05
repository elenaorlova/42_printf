/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 22:05:03 by ashari            #+#    #+#             */
/*   Updated: 2019/05/20 22:05:04 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *str, char *sub, int index)
{
	int		i;
	char	*res;
	int		tmp;
	int		s;

	res = ft_strnew(ft_strlen(str) + ft_strlen(sub));
	i = -1;
	while (++i < index)
		res[i] = str[i];
	tmp = i;
	s = 0;
	while (sub[s])
		res[i++] = sub[s++];
	while (str[tmp])
		res[i++] = str[tmp++];
	free(str);
	free(sub);
	return (res);
}
