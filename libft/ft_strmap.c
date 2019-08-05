/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: den <den@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:17:58 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 16:21:59 by den              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		newstr[i] = f(s[i]);
	newstr[i] = '\0';
	return (newstr);
}
