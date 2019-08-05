/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:35:49 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/19 21:30:51 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = (char *)malloc(size);
	if (!mem)
		exit(-1);
	while (i < size)
		mem[i++] = 0;
	return ((void *)mem);
}
