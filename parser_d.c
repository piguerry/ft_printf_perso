/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:23:28 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:55:48 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parser_d_digitd(char *nbr, t_fl f)
{
	int		count;
	int		len;
	char	*str;
	char	*space;

	count = 0;
	str = NULL;
	len = ft_strlen(nbr);
	if (f.digitd < len)
		return (nbr);
	if (!(space = malloc(sizeof(char) * (f.digitd - len + 1))))
		return (0);
	while (count < (f.digitd - len))
	{
		space[count] = ' ';
		count++;
	}
	space[count] = '\0';
	if (f.neg == 0)
		str = ft_strjoin(space, nbr);
	else
		str = ft_strjoin(nbr, space);
	free(space);
	free(nbr);
	return (str);
}

static char	*nbrisneg(t_fl f, char *zero, char *nbr)
{
	char	*buff;
	char	*str;

	buff = NULL;
	str = NULL;
	if (f.zero == 1)
		buff = ft_strjoin("-", zero);
	else
		buff = ft_strjoin("-0", zero);
	str = ft_strjoin(buff, &nbr[1]);
	free(buff);
	return (str);
}

static char	*parser_d_ddigit(char *nbr, t_fl f, char *str)
{
	int		count;
	int		len;
	char	*zero;

	count = 0;
	zero = NULL;
	len = ft_strlen(nbr);
	if (f.ddigit < len)
		return (nbr);
	if (!(zero = malloc(sizeof(char) * (f.ddigit - len + 1))))
		return (0);
	while (count < (f.ddigit - len))
	{
		zero[count] = '0';
		count++;
	}
	zero[count] = '\0';
	if (nbr[0] == '-' && (len - 1) < f.ddigit)
		str = nbrisneg(f, zero, nbr);
	else
		str = ft_strjoin(zero, nbr);
	free(zero);
	free(nbr);
	return (str);
}

char		*parser_d(int arg, t_fl f, int *len)
{
	char	*nbr;
	char	*str;

	nbr = NULL;
	str = NULL;
	if (!(nbr = ft_itoa(arg)))
		return (0);
	if (arg == 0 && f.dot == 1 && f.ddigit == 0)
		nbr[0] = '\0';
	str = parser_d_ddigit(nbr, f, str);
	if (f.digitd > 0 && f.digitd > f.ddigit)
		str = parser_d_digitd(str, f);
	*len = ft_strlen(str);
	return (str);
}
