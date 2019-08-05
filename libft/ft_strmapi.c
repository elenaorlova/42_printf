/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:17:06 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/06 21:43:54 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[++i])
		newstr[i] = f(i, s[i]);
	newstr[i] = '\0';
	return (newstr);
}
