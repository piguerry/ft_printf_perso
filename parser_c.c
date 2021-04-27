/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:23:19 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 14:03:14 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parser_c_digitd(char c, t_fl f, int *len)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	if (f.digitd < 1)
		return (0);
	if (!(str = malloc(sizeof(char) * (f.digitd + 1))))
		return (0);
	while (count <= (f.digitd - 1))
	{
		if (f.neg == 1 && count == 0)
			str[0] = c;
		else
			str[count] = ' ';
		if (f.neg == 0 && count == (f.digitd - 1))
			str[count] = c;
		count++;
	}
	str[count] = '\0';
	*len = count;
	return (str);
}

static char	*parser_c_ddigit(char c, t_fl f, int *len)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	if (f.ddigit < 1)
		return (0);
	if (!(str = malloc(sizeof(char) * (f.ddigit + 1))))
		return (0);
	while (count <= (f.ddigit - 1))
	{
		if (f.neg == 1 && count == 0)
			str[0] = c;
		else
			str[count] = '0';
		if (f.neg == 0 && count == (f.ddigit - 1))
			str[count] = c;
		count++;
	}
	str[count] = '\0';
	*len = count;
	return (str);
}

char		*ft_chardup(char c)
{
	char *str;

	str = NULL;
	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char		*parser_c(char arg, t_fl f, int *len)
{
	char	*str;

	str = NULL;
	*len = 1;
	if (f.digitd > 0)
		str = parser_c_digitd(arg, f, len);
	else if (f.ddigit > 0 && f.zero != 0)
		str = parser_c_ddigit(arg, f, len);
	if (!str)
		if (!(str = ft_chardup(arg)))
			return (0);
	return (str);
}
