/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/02/05 22:24:06 by scoron           ###   ########.fr       */
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
	//printf("res : %s, size : %d, len : %zu, preci : %zu\n", res, size, len, p->preci);
	if (size < p->min)
		size = p->min;
	if (!(res2 = ft_strnew(size)))
		return (0);
	res2 = ft_memset(res2, '?', size);
	return (res2);
} 

char		*ft_fill_dtoa(long long itg, int dot, t_ftp *p)
{
	char			*res;
	long long		tmp;
	size_t			len;

	tmp = itg;
	len = itg == 0 ? p->preci + 1 : 1;
	while (tmp /= 10)
		len++;
	dot == 0 ? 0 : (len += 1);
	itg < 0 ? (len += 1) && (dot += dot == 0 ? 0 : 1) : 0;
	tmp = itg > 0 ? itg : -itg;
	res = ft_strnew(len);
	while (len > 1)
	{
		if (dot && (int)len == dot + 1)
			res[--len] = '.';
		res[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	*res = itg < 0 ? '-' : tmp % 10 + '0';
	//printf("res : %s, itg : %lld, len : %zu, dot : %d\n", res, itg, len, dot);
	return (res);
}

char		*ft_dtoa(long double flt, t_ftp *p)
{
	long long		itg;
	int				dot;
	int				prec;

	itg = (long long)flt;
	prec = p->preci;
	dot = p->preci == 0 ? 0 : 1;
	while (dot && (itg /= 10))
		dot++;
	while (prec--)
		flt *= 10;
	itg = flt > 0 ? (long long)flt : -(long long)flt;
	if ((long long)(flt * 10) % 10 > 4 || (long long)(flt * 10) % 10 < -4)
		itg += 1;
	itg *= flt > 0 ? 1 : -1;
	//printf("itg : %lld, flt : %Lf, dot : %d\n", itg, flt, dot);
	return (ft_fill_dtoa(itg, dot, p));
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
