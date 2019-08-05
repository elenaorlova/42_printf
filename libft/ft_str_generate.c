/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:01:15 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 23:01:21 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_generate(int len, char chr)
{
	char *new;

	if (len < 1)
		return (ft_strnew(0));
	new = (char *)malloc(len + 1);
	new[len] = 0;
	while (len)
		new[len-- - 1] = chr;
	return (new);
}
