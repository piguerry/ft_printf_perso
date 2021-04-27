/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:17:52 by piguerry          #+#    #+#             */
/*   Updated: 2019/11/11 15:16:56 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*buff;

	len = 0;
	while (s1[len])
		len++;
	if (!(buff = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (s1[len])
	{
		buff[len] = s1[len];
		len++;
	}
	buff[len] = '\0';
	return (buff);
}
