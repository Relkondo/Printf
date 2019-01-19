/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 17:44:06 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*flags_impact(t_ftp *p, char *res, char c)
{
	char	*res2;

	res2 = calculate_size(p, res, c);
	p->i = 0;
	if (((p->f & F_SPACE) || (p->f & F_PLUS)) && res[0] != '-')
		res2[p->i++] = (p->f & F_PLUS) ? '+' : ' ';
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
	{
		res2[p->i++] = '0';
		c != 'o' ? res2[p->i++] = c : 0 ;
	}
	flag_preci(p, res, res2, c);
	if (!(p->f & F_MINUS))
		flag_zero(p, res2);
	return (res2);
}

//printf("p->f : %d, i : %d, res2 : %s\n", p->f, i, res2);
//doit prendre en compte les flags hhll (et L pour f)

void		cs_int(t_ftp *p, char c)
{
	int		n;
	char	*res;

	n = va_arg(p->va, int);
	res = (c == 'd' || c == 'D' || c == 'i') ? ft_itoa(n) : ft_uitoa(n);
	if (c == 'o' || c == 'O')
		res = ft_convert_base(res, "0123456789", "01234567");
	else if (c == 'X')
		res = ft_convert_base(res, "0123456789", "0123456789ABCDEF");
	else if (c == 'x')
		res = ft_convert_base(res, "0123456789", "0123456789abcdef");
	res = flags_impact(p, res, c);
	buffer(p, ft_strlen(res), res);
}

void		cs_char(t_ftp *p, char c)
{
	c = (char)va_arg(p->va, int);
	buffer(p, 1, &c);
}

void		cs_str(t_ftp *p, char c)
{
	char	*str;

	(void)c;
	str = va_arg(p->va, char *);
	buffer(p, ft_strlen(str), str);
}
