/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:30:31 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/21 22:15:27 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*s;
	unsigned long	*d;
	unsigned char	*sc;
	unsigned char	*dc;
	size_t			nb;

	d = (unsigned long *)dst;
	s = (unsigned long *)src;
	nb = n / sizeof(unsigned long);
	while (nb--)
		*(d++) = *(s++);
	nb = n % sizeof(unsigned long);
	sc = (unsigned char *)s;
	dc = (unsigned char *)d;
	while (nb--)
		*(dc++) = *(sc++);
	return (dst);
}
