/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:24:27 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:46:26 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parser_x_digitd(char *nbr, t_fl f)
{
	int		count;
	int		len;
	char	*space;
	char	*str;

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

static char	*parser_x_ddigit(char *nbr, t_fl f, char *str)
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
	str = ft_strjoin(zero, nbr);
	free(zero);
	free(nbr);
	return (str);
}

char		*conv_to_hexa(unsigned int arg, char *base)
{
	int				count;
	unsigned long	buff;
	char			*str;

	count = 1;
	str = NULL;
	buff = arg;
	while ((buff /= 16) != 0)
		count++;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count] = base[(arg % 16)];
		arg /= 16;
		count--;
	}
	return (str);
}

char		*parser_x(unsigned long arg, char *base, t_fl f, int *len)
{
	char	*nbr;
	char	*str;

	nbr = NULL;
	str = NULL;
	if (!(nbr = conv_to_hexa(arg, base)))
		return (0);
	if (arg == 0 && f.dot == 1 && f.ddigit == 0)
		nbr[0] = '\0';
	str = parser_x_ddigit(nbr, f, str);
	if (f.digitd > 0 && f.digitd > f.ddigit)
		str = parser_x_digitd(str, f);
	*len = ft_strlen(str);
	return (str);
}
