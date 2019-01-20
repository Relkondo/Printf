/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 17:53:32 by scoron           ###   ########.fr       */
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
				c != 'o' ? res2[p->i++] = c : 0;
		}
		flag_preci(p, res, res2, c);
		if (!(p->f & F_MINUS))
				flag_zero(p, res2);
		return (res2);
}

long long			ft_arg(t_ftp *p)
{
		long long			n;

		n = 0;
		if (p->f & F_LONG)
				n = (p->f & F_LONG2) ? va_arg(p->va, long long) :
						((long long)va_arg(p->va, long));
		else if (p->f & F_SHORT)
				n = (p->f & F_CHAR) ? (long long)((char)va_arg(p->va, int)) :
						(long long)((short)va_arg(p->va, int));
		return (n);
}

unsigned long long	ft_uarg(t_ftp *p)
{
		unsigned long long	u;

		u = 0;
		if (p->f & F_LONG)
				u = (p->f & F_LONG2) ? va_arg(p->va, unsigned long long) :
						((unsigned long long)va_arg(p->va, unsigned long));
		else if (p->f & F_CHAR)
				u = (unsigned long long)((unsigned char)va_arg(p->va, int));
		else if (p->f & F_SHORT)
				u = (unsigned long long)((unsigned short)va_arg(p->va, int));
		return (u);
}

void		cs_int(t_ftp *p, char c)
{
		long long			n;
		unsigned long long	u;
		char				*res;

		n = (c == 'd' || c == 'D' || c == 'i') ? ft_arg(p) : 0;
		u = (c == 'd' || c == 'D' || c == 'i') ? 0 : ft_uarg(p);
		res = (c == 'd' || c == 'D' || c == 'i') ? ft_itoa(n) : ft_uitoa(u);
		printf("res : %s\n", res);
		if (c == 'o' || c == 'O')
				res = ft_uconvert_base(res, "0123456789", "01234567");
		else if (c == 'X')
				res = ft_uconvert_base(res, "0123456789", "0123456789ABCDEF");
		else if (c == 'x')
				res = ft_uconvert_base(res, "0123456789", "0123456789abcdef");
		printf("res : %s\n", res);
		res = flags_impact(p, res, c);
		printf("res : %s\n", res);
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
