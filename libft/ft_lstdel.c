/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:25:33 by den               #+#    #+#             */
/*   Updated: 2019/04/10 22:10:07 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **target;
	t_list *tmp;

	target = alst;
	while (*alst && del)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
	free(*target);
	*target = NULL;
}
