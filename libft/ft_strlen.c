/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:09:11 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 00:51:04 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_byte(const char *ptr)
{
	int	ret;

	ret = -1;
	if (ptr[0] == '\0')
		ret = 0;
	else if (ptr[1] == '\0')
		ret = 1;
	else if (ptr[2] == '\0')
		ret = 2;
	else if (ptr[3] == '\0')
		ret = 3;
	else if (ptr[4] == '\0')
		ret = 4;
	else if (ptr[5] == '\0')
		ret = 5;
	else if (ptr[6] == '\0')
		ret = 6;
	else if (ptr[7] == '\0')
		ret = 7;
	return (ret);
}

size_t		ft_strlen(const char *s)
{
	int					x;
	const char			*ptr;
	const unsigned long	*lptr;

	x = 0;
	ptr = s;
	while (((unsigned long)ptr & sizeof(long)) - 1)
	{
		if (*ptr == '\0')
			return (ptr - s);
		ptr++;
	}
	lptr = (const unsigned long *)ptr;
	while (1)
	{
		if ((*lptr - LAST_BIT) & FIRST_BIT)
		{
			ptr = (const char *)(lptr);
			if ((x = test_byte(ptr)) >= 0)
				break ;
		}
		lptr++;
	}
	return (ptr - s + x);
}
