/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:04:18 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/03 19:05:50 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = -1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[++i])
		if (str1[i] != str2[i])
			break ;
	return (str1[i] - str2[i]);
}
