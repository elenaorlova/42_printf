/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:32:47 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/11 13:13:15 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last;

	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	return ((*s == c) ? (char *)s : last);
}
