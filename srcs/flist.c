/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:41:10 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 16:41:12 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flist_push(t_flist **head, t_flist *node)
{
	t_flist *tmp;

	if (!*head)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_flist	*flist_create(char *format, char *output)
{
	t_flist *new;

	new = (t_flist*)malloc(sizeof(t_flist));
	new->format = format;
	new->output = output;
	new->width = -1;
	new->precision = -1;
	new->type = -1;
	new->length = NULL;
	new->flags = NULL;
	new->next = NULL;
	return (new);
}
