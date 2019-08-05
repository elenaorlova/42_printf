/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:18:36 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/03 19:19:23 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (size + 1 == 0)
		return (NULL);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
