/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:24:00 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:26:53 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parser_s_digit(char *arg, t_fl f, int len)
{
	char	*str;
	char	*space;
	int		count;

	count = 0;
	str = NULL;
	space = NULL;
	if (f.digitd < len)
		return (ft_strdup(arg));
	if (!(space = malloc(sizeof(char) * (f.digitd - len + 1))))
		return (0);
	while (count < f.digitd - len)
	{
		space[count] = ' ';
		count++;
	}
	space[count] = '\0';
	if (f.neg == 0)
		str = ft_strjoin(space, arg);
	else
		str = ft_strjoin(arg, space);
	free(space);
	return (str);
}

char	*parser_s_digitd(t_fl f, char *str, int len)
{
	int		count;
	char	*buff;
	char	*newstr;

	count = 0;
	buff = NULL;
	newstr = NULL;
	if (f.digitd < len)
		return (str);
	if (!(buff = malloc(sizeof(char) * ((f.digitd - len) + 1))))
		return (0);
	while (count < f.digitd - len)
	{
		buff[count] = ' ';
		count++;
	}
	buff[count] = '\0';
	if (f.neg == 0)
		newstr = ft_strjoin(buff, str);
	else
		newstr = ft_strjoin(str, buff);
	free(buff);
	free(str);
	return (newstr);
}

char	*parser_s_ddigit(char *arg, t_fl f, int len)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	if (f.ddigit < 0)
		return (ft_strdup(arg));
	if (f.ddigit > len)
		f.ddigit = len;
	if (!(str = malloc(sizeof(char) * (f.ddigit + 1))))
		return (0);
	while (count < f.ddigit)
	{
		str[count] = arg[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*parser_s(char *arg, t_fl f, int *len)
{
	char	*str;
	int		count;
	char	*buff;

	str = NULL;
	buff = NULL;
	if (arg == 0)
		buff = ft_strdup("(null)");
	else
		buff = ft_strdup(arg);
	count = ft_strlen(buff);
	if (f.digitd > 0 && f.dot == 0)
		str = parser_s_digit(buff, f, count);
	else
	{
		if (f.dot == 1)
			str = parser_s_ddigit(buff, f, count);
		if (f.digitd > 0)
			str = parser_s_digitd(f, str, ft_strlen(str));
		if (str == NULL)
			str = ft_strdup(buff);
	}
	*len = ft_strlen(str);
	free(buff);
	return (str);
}
