/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:27:07 by piguerry          #+#    #+#             */
/*   Updated: 2019/11/11 15:08:14 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convstr(const char *str, int count, int is_neg)
{
	unsigned long long	buff;
	int					nb;

	buff = 0;
	nb = 0;
	while (str[count] >= '0' && str[count] <= '9')
	{
		buff *= 10;
		buff += (str[count] - '0');
		count++;
		nb++;
		if (nb == 20 && is_neg == 0)
			return (-1);
		if (nb == 20 && is_neg == 1)
			return (0);
	}
	if (is_neg != 0)
		return ((int)-buff);
	return ((int)buff);
}

int			ft_atoi(const char *str)
{
	int			count;
	int			is_neg;

	count = 0;
	is_neg = 0;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			is_neg++;
		count++;
	}
	return (convstr(str, count, is_neg));
}
