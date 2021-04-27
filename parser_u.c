/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:24:17 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/27 12:45:19 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parser_u_digitd(char *nbr, t_fl f)
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

static char	*parser_u_ddigit(char *nbr, t_fl f, char *str)
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

char		*parser_u(unsigned int arg, t_fl f, int *len)
{
	char	*nbr;
	char	*str;

	nbr = NULL;
	str = NULL;
	if (!(nbr = ft_itoa_u(arg)))
		return (0);
	if (arg == 0 && f.dot == 1 && f.ddigit == 0)
		nbr[0] = '\0';
	str = parser_u_ddigit(nbr, f, str);
	if (f.digitd > 0 && f.digitd > f.ddigit)
		str = parser_u_digitd(str, f);
	*len = ft_strlen(str);
	return (str);
}
