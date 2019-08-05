/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:09:58 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/10 20:33:34 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*copy(const void *src, size_t n)
{
	void	*cpy;
	size_t	i;

	i = 0;
	cpy = malloc(n);
	if (!cpy)
		return (NULL);
	while (i < n)
	{
		*((char*)cpy + i) = *((char*)src + i);
		i++;
	}
	return (cpy);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content_size = content ? content_size : 0;
	new->content = content ? copy(content, content_size) : NULL;
	new->next = NULL;
	return (new);
}
