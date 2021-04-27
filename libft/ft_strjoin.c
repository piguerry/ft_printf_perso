/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:42:32 by piguerry          #+#    #+#             */
/*   Updated: 2019/11/11 18:37:31 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*str;

	lens1 = 0;
	lens2 = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (s1[lens1])
		lens1++;
	while (s2[lens2])
		lens2++;
	if (!(str = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (0);
	lens1 = 0;
	while (s1[lens1])
	{
		str[lens1] = s1[lens1];
		lens1++;
	}
	lens2 = 0;
	while (s2[lens2])
		str[lens1++] = s2[lens2++];
	str[lens1] = '\0';
	return (str);
}
