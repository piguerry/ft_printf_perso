/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:28:34 by piguerry          #+#    #+#             */
/*   Updated: 2021/04/26 16:32:53 by piguerry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_fl
{
	int		digit;
	int		digitd;
	int		ddigit;
	int		dot;
	int		neg;
	int		zero;
	char	type;
}				t_fl;

typedef struct	s_plist
{
	void			*content;
	int				len;
	struct s_plist	*next;
}				t_plist;

int				ft_printf(const char *format, ...);
t_plist			*parser(const char *format, va_list ap, t_fl f);
char			*parser_c(char arg, t_fl f, int *len);
char			*parser_s(char *arg, t_fl f, int *len);
char			*parser_p(void *arg, t_fl f, int *len);
char			*parser_d(int arg, t_fl f, int *len);
char			*parser_u(unsigned int arg, t_fl f, int *len);
char			*parser_x(unsigned long arg, char *base, t_fl f, int *len);
char			*ft_itoa_u(unsigned int n);
void			initfl(t_fl *f);
int				ft_putstr(char *str);
int				ft_strlen(const char *str);
t_plist			*ft_lstadd(t_plist *alst, t_plist *new);
t_plist			*ft_newlst(void *content, int len);
void			ft_plstdelone(t_plist *lst, void (*del)(void*));
void			ft_plstclear(t_plist **lst, void (*del)(void*));
int				read_lst(t_plist **lst);
void			flagparser(const char *flag, t_fl *f, va_list ap, int *cursor);
#endif
