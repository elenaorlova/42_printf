/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:28:21 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 19:33:11 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		i;
	size_t	befsp;
	size_t	aftsp;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	befsp = 0;
	aftsp = 0;
	while (is_space(s[i++]))
		befsp++;
	if (befsp == len)
		return (ft_strnew(0));
	i = len;
	while (is_space(s[--i]))
		aftsp++;
	trimmed = ft_strnew(len - befsp - aftsp);
	if (!trimmed)
		return (NULL);
	ft_strcpy(trimmed, ft_strsub(s, (unsigned int)befsp, len - befsp - aftsp));
	return (trimmed);
}
