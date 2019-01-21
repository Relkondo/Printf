/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/01/21 20:38:33 by scoron           ###   ########.fr       */
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
	//printf("len : %zu\n", len);
	size = 0;
	if (((p->f & F_PLUS) || (p->f & F_SPACE)) && (res[0] != '-' || c == 's' || c == 'c'))
		size += 1;
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
		size += (c == 'o') ? 1 : 2;
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
	//printf("res2 %s, size : %d\n", res2, size);
	return (res2);
}

t_val	*ft_arg(t_ftp *p)
{
	t_val		n;

	n = 0;
	if (p->f & F_INTMAX)
		n.im = va_arg(p->va, intmax_t);
	else if (p->f & F_LONG2)
		n.ll = va_arg(p->va, long long)
	else if (p->f & F_LONG)
		n.l = va_arg(p->va, long);
	else if (p->f & F_SHORT)

		n.s = p->f & F_CHAR ? (intmax_t)((char)va_arg(p->va, int))
			: (intmax_t)((short)va_arg(p->va, int));
	else
		n. = (intmax_t)(va_arg(p->va, int));
	return (&n);
}

uintmax_t	ft_uarg(t_ftp *p)
{
	uintmax_t	u;

	u = 0;
	if (p->f & F_INTMAX)
		u = va_arg(p->va, uintmax_t);
	else if (p->f & F_LONG)
		u = p->f & F_LONG2 ? (uintmax_t)va_arg(p->va, unsigned long long)
			: ((uintmax_t)va_arg(p->va, unsigned long));
	else if (p->f & F_CHAR)
		u = p->f & F_SHORT ? (uintmax_t)((unsigned char)va_arg(p->va, int))
			: (uintmax_t)((unsigned short)va_arg(p->va, int));
	else
		u = (long)va_arg(p->va, int);
	return (u);
}
