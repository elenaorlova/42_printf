/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:27:10 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 17:33:48 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	intlen(unsigned long long n)
{
	size_t len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa_uns(unsigned long long n)
{
	char	*res;
	size_t	len;

	len = intlen(n);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
