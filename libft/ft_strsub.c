/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:19:33 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/06 21:48:35 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*newstr;

	if (!s)
		return (NULL);
	newstr = ft_strnew(len);
	return (newstr ? ft_strncpy(newstr, s + start, len) : NULL);
}
