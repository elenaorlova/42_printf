/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:15:04 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/05 23:09:05 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		else
			while (i != n)
				dest[i++] = 0;
	}
	return (dest);
}
