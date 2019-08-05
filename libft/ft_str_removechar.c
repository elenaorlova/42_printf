/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_removechar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:01:52 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 23:02:26 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_removechar(char *str, char chr)
{
	char	*new;
	int		i;

	if (!str)
		return (0);
	new = ft_strnew(0);
	i = 0;
	while (str[i])
	{
		if (str[i] != chr)
			ft_strpushchar(&new, str[i]);
		i++;
	}
	free(str);
	return (new);
}
