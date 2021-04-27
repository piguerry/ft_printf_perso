/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:49:27 by piguerry          #+#    #+#             */
/*   Updated: 2019/11/11 18:24:43 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	powerten(int nb, int pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nb);
	return (powerten(nb * 10, pow - 1));
}

static char	*niszero(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static void	fillstr(char *str, int len, long int n, int isneg)
{
	int	count;

	count = 0;
	if (isneg == 1)
	{
		count = 1;
		n = -n;
	}
	while (len >= 0)
	{
		str[count] = ((n / (powerten(10, len))) % 10) + '0';
		len--;
		count++;
	}
	str[count] = '\0';
	if (isneg == 1)
		str[0] = '-';
}

char		*ft_itoa(int n)
{
	int			isneg;
	char		*str;
	int			len;
	long int	buff;

	if (n == 0)
		return (niszero());
	isneg = 0;
	len = 0;
	buff = n;
	if (n < 0)
		isneg = 1;
	while (buff != 0)
	{
		len++;
		buff /= 10;
	}
	buff = n;
	if (!(str = (char*)malloc(sizeof(char) * (isneg + len + 1))))
		return (0);
	len--;
	fillstr(str, len, buff, isneg);
	return (str);
}
