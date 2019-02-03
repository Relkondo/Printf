/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/02/01 16:09:59 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*calculate_size(t_ftp *p, char *res, char c)
{
	char	*res2;
	int		size;
	size_t	len;

	len = ft_strlen(res);
	size = 0;
	if (((p->f & F_SPACE) || (p->f & F_PLUS))
			&& res[0] != '-' && c != 's' && c != 'c' && c != '%' && c != 'u')
		size += 1;
	if ((c == 'x' || c == 'X' || c == 'o') && p->f & F_SHARP)
		size += (c == 'o') ? 1 : 2;
	if (res[0] == '-' && c != 's' && c != 'c' && c != '%' && c != 'f')
		p->preci++;
	if (c == 'f')
		size += p->preci + ft_strnlen(res, '.');
	else if (c == 's' && p->preci != 0)
		p->preci > len ? (size += len) : (size += p->preci);
	else
		p->preci > len ? (size += p->preci) : (size += len);
	if (size < p->min)
		size = p->min;
	if (!(res2 = ft_strnew(size)))
		return (0);
	res2 = ft_memset(res2, '?', size);
	return (res2);
}

char		*ft_ditoa(long double flt)
{
	char			*res;
	int				j;
	long double		tmp;
	int				i;

	i = (flt < 0) ? 1 : 0;
	flt < 1 && flt > -1 ? i++ : 0;
	j = (flt = (long long)flt) ? 0 : 1;
	tmp = flt;
	while ((long long)tmp && ++i)
		tmp /= 10;
	tmp = flt;
	while ((tmp = tmp - (long long)tmp) && ++j)
		tmp *= 10;
	tmp = flt;
	*res = ft_strnew(i + j);
	while ((tmp = tmp - (long long)tmp))
	{
		tmp *= 10;
		res[i + j++] = '0' + (long long)tmp;
	}
	flt = (long long)flt ? 0 : res[--i] = '.';
	while ((long long)flt)
	{
		res[--i] = (long long)flt % 10;
		flt /= 10;
	}
	i == 0 ? 0 : res[0] = '-';
	return (res);
}

intmax_t	ft_arg(t_ftp *p)
{
	intmax_t			n;

	n = 0;
	if (p->f & F_INTMAX || p->f & F_SIZET)
		n = va_arg(p->va, intmax_t);
	else if (p->f & F_LONG)
		n = (p->f & F_LONG2) ? va_arg(p->va, long long) :
			va_arg(p->va, long);
	else if (p->f & F_SHORT)
		n = (p->f & F_CHAR) ? (char)va_arg(p->va, int) :
			(short)va_arg(p->va, int);
	else
		n = (int)(va_arg(p->va, int));
	return (n);
}

uintmax_t	ft_uarg(t_ftp *p)
{
	uintmax_t			u;

	u = 0;
	if (p->f & F_INTMAX || p->f & F_SIZET)
		u = va_arg(p->va, uintmax_t);
	else if (p->f & F_LONG)
		u = (p->f & F_LONG2) ? va_arg(p->va, unsigned long long)
			: va_arg(p->va, unsigned long);
	else if (p->f & F_SHORT)
		u = (p->f & F_CHAR) ? (unsigned char)va_arg(p->va, unsigned int)
			: (unsigned short)va_arg(p->va, unsigned int);
	else
		u = va_arg(p->va, unsigned int);
	return (u);
}
