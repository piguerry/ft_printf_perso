/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:24:44 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:40:08 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plstdelone(t_plist *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
	lst = NULL;
}

void	ft_plstclear(t_plist **lst, void (*del)(void *))
{
	t_plist *cursor;
	t_plist *buff;

	cursor = NULL;
	buff = NULL;
	if (lst == 0 || *lst == 0)
		return ;
	cursor = *lst;
	buff = 0;
	while (cursor)
	{
		if (cursor->next)
			buff = cursor->next;
		else
			buff = 0;
		ft_plstdelone(cursor, (*del));
		cursor = buff;
	}
	*lst = 0;
}

int		read_lst(t_plist **lst)
{
	int		count;
	t_plist	*cursor;

	cursor = NULL;
	count = 0;
	if (lst == 0)
		return (0);
	cursor = *lst;
	while (cursor)
	{
		count += write(1, cursor->content, cursor->len);
		cursor = cursor->next;
	}
	return (count);
}

t_plist	*ft_newlst(void *content, int len)
{
	t_plist *new;

	new = NULL;
	if (!(new = (t_plist*)malloc(sizeof(t_plist))))
		return (0);
	new->content = content;
	new->len = len;
	new->next = 0;
	return (new);
}

t_plist	*ft_lstadd(t_plist *alst, t_plist *new)
{
	t_plist *buff;

	buff = NULL;
	if (alst == 0)
		return (new);
	buff = alst;
	while (buff->next)
		buff = buff->next;
	buff->next = new;
	return (alst);
}
