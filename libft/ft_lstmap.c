/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:19:31 by den               #+#    #+#             */
/*   Updated: 2019/04/10 22:30:33 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list *map;
	t_list *newel;

	if (!lst || !f)
		return (NULL);
	map = NULL;
	while (lst)
	{
		newel = ft_lstnew(lst->content, lst->content_size);
		ft_lstpush(&map, f(newel));
		lst = lst->next;
	}
	return (map);
}
