/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:24:51 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:35:43 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	t_plist		*lst;
	t_fl		f;

	len = 0;
	va_start(ap, format);
	lst = parser(format, ap, f);
	len = read_lst(&lst);
	ft_plstclear(&lst, (*free));
	va_end(ap);
	return (len);
}
