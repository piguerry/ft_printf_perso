/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:21:08 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/26 16:58:39 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initfl(t_fl *f)
{
	f->neg = 0;
	f->dot = 0;
	f->digit = 0;
	f->ddigit = 0;
	f->digitd = 0;
	f->zero = 0;
}

static void	starflag(va_list ap, t_fl *f)
{
	if (f->dot == 0)
		f->digitd = va_arg(ap, int);
	else
		f->ddigit = va_arg(ap, int);
}

static void	finishflag(t_fl *f)
{
	if (f->neg == 1 && f->digitd > 0)
		f->digitd = f->digitd * (-1);
	if (f->digitd > 0 && ((f->zero == 1 && f->ddigit < 0)
				|| (f->zero == 1 && f->dot == 0)))
	{
		f->ddigit = f->digitd;
		f->digitd = 0;
	}
	else
		f->zero = 0;
	if (f->digitd < 0)
	{
		f->neg = 1;
		f->digitd = f->digitd * (-1);
	}
}

void		flagparser(const char *flag, t_fl *f, va_list ap, int *cursor)
{
	initfl(f);
	while (flag[*cursor] != '%' && !(ft_isalpha(flag[*cursor])))
	{
		if (flag[*cursor] == '0')
			f->zero = 1;
		if (flag[*cursor] == '-')
			f->neg = 1;
		else if (ft_isdigit(flag[*cursor]))
		{
			if (f->dot == 0)
				f->digitd = ft_atoi(&flag[*cursor]);
			else
				f->ddigit = ft_atoi(&flag[*cursor]);
			while (ft_isdigit(flag[*cursor + 1]))
				*cursor = *cursor + 1;
		}
		else if (flag[*cursor] == '*')
			starflag(ap, f);
		else if (flag[*cursor] == '.')
			f->dot = 1;
		*cursor = *cursor + 1;
	}
	finishflag(f);
	f->type = flag[*cursor];
}
