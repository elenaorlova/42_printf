/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:58:01 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 18:26:04 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_strlen2(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

static size_t		get_word_count(const char *s, char del)
{
	size_t i;
	size_t strlen;
	size_t count;

	strlen = ft_strlen2(s);
	count = 0;
	i = 0;
	while (i < strlen)
	{
		if (s[i] != del && (s[i + 1] == del || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int			get_word_len(int start_ind, const char *s, char del)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[start_ind + i] != del && s[start_ind + i] != '\0')
		i++;
	return (i);
}

static void			str_copy(const char *src, char *dest, int src_len)
{
	int i;

	i = 0;
	while (i < src_len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char				**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		a[5];

	a[4] = ft_strlen2(s);
	a[3] = get_word_count(s, c);
	a[2] = 0;
	a[0] = 0;
	res = (char **)malloc(sizeof(char *) * (a[3] + 1));
	if (!res || !s)
		return (NULL);
	while (a[0] < a[4])
	{
		if (s[a[0]] != c)
		{
			a[1] = get_word_len(a[0], s, c);
			res[a[2]] = (char *)malloc(sizeof(char) * (a[1] + 1));
			str_copy(&s[a[0]], &res[a[2]][0], a[1] + 1);
			a[2]++;
			a[0] += a[1];
		}
		a[0]++;
	}
	res[a[3]] = 0;
	return (res);
}
