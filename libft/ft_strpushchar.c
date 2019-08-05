/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpushchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:58:51 by ashari            #+#    #+#             */
/*   Updated: 2019/05/20 21:58:53 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpushchar(char **str, int chr)
{
	char	*new;
	size_t	strlen;

	if (!*str)
		*str = ft_strnew(0);
	strlen = ft_strlen_safe(*str);
	new = ft_strnew(strlen + 1);
	ft_strcpy(new, *str);
	new[strlen] = chr;
	free(*str);
	*str = new;
}
