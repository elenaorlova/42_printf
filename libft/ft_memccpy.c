/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:29:52 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/21 22:14:23 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	len;

	if ((ptr = ft_memchr(src, c, n)))
	{
		len = ptr - src + 1;
		ft_memcpy(dst, src, len);
		return (dst + len);
	}
	ft_memcpy(dst, src, n);
	return (0);
}
