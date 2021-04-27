/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:23:08 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 14:42:29 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*selecttype(va_list ap, t_fl f, int *len)
{
	char	type;

	type = f.type;
	if (type == 'd' || type == 'i')
		return (parser_d(va_arg(ap, int), f, len));
	if (type == 'u')
		return (parser_u(va_arg(ap, unsigned int), f, len));
	if (type == 'x')
		return (parser_x(va_arg(ap, int), "0123456789abcdef", f, len));
	if (type == 'X')
		return (parser_x(va_arg(ap, int), "0123456789ABCDEF", f, len));
	if (type == 'c')
		return (parser_c(va_arg(ap, int), f, len));
	if (type == '%')
		return (parser_c('%', f, len));
	if (type == 's')
		return (parser_s(va_arg(ap, char *), f, len));
	if (type == 'p')
		return (parser_p(va_arg(ap, void *), f, len));
	return (0);
}

char	*stronly(const char *format, int *start, int *len)
{
	int		count;
	int		cursor;
	char	*str;

	str = NULL;
	count = *start;
	cursor = 0;
	while (format[*start] && format[*start] != '%')
		*start += 1;
	if (!(str = malloc(sizeof(char) * (*start - count + 1))))
		return (0);
	while (count < *start)
	{
		str[cursor] = format[count];
		count++;
		cursor++;
	}
	str[cursor] = '\0';
	*len = ft_strlen(str);
	return (str);
}

t_plist	*parser(const char *format, va_list ap, t_fl f)
{
	int		len;
	int		cursor;
	char	*str;
	t_plist	*lst;

	cursor = 0;
	str = NULL;
	lst = NULL;
	while (format[cursor])
	{
		if (format[cursor] != '%')
		{
			str = stronly(format, &cursor, &len);
			lst = ft_lstadd(lst, (ft_newlst(str, len)));
		}
		if (format[cursor] == '%')
		{
			cursor++;
			flagparser(format, &f, ap, &cursor);
			cursor++;
			str = selecttype(ap, f, &len);
			lst = ft_lstadd(lst, ft_newlst(str, len));
		}
	}
	return (lst);
}
