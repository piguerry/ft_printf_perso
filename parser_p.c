/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:23:43 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:25:45 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*conv_to_hexap(void *arg, char *base)
{
	int				count;
	unsigned long	buff;
	char			*str;

	count = 1;
	str = NULL;
	buff = (unsigned long)arg;
	while ((buff /= 16) != 0)
		count++;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	count--;
	buff = (unsigned long)arg;
	while (buff != 0)
	{
		str[count] = base[(buff % 16)];
		buff /= 16;
		count--;
	}
	return (str);
}

static char	*parser_p_digitd(t_fl f, char *str)
{
	int		count;
	int		len;
	char	*space;
	char	*join;

	count = 0;
	space = NULL;
	join = NULL;
	len = ft_strlen(str);
	if (!(space = malloc(sizeof(char) * (f.digitd - len + 1))))
		return (0);
	while (count < f.digitd - len)
	{
		space[count] = ' ';
		count++;
	}
	space[count] = '\0';
	if (f.neg == 0)
		join = ft_strjoin(space, str);
	else
		join = ft_strjoin(str, space);
	free(space);
	free(str);
	return (join);
}

char		*arg_is_null(t_fl f)
{
	char	*str;

	str = NULL;
	if (!(str = malloc(sizeof(char) * 4)))
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '\0';
	str[3] = '\0';
	if (f.dot == 0)
		str[2] = '0';
	return (str);
}

char		*parser_p(void *arg, t_fl f, int *len)
{
	char	*str;
	char	*buff;

	str = NULL;
	buff = NULL;
	if (arg == 0)
	{
		if (!(str = arg_is_null(f)))
			return (0);
	}
	else
	{
		buff = conv_to_hexap(arg, "0123456789abcdef");
		str = ft_strjoin("0x", buff);
		free(buff);
	}
	if (f.digitd != 0)
		str = parser_p_digitd(f, str);
	*len = ft_strlen(str);
	return (str);
}
