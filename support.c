/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/01/21 17:12:20 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*calculate_size(t_ftp *p, char *res, char c)
{
	char	*res2;
	int		size;
	size_t	len;

	len = ft_strlen(res);
	size = 0;
	if (((p->f & F_PLUS) || (p->f & F_SPACE)) && (res[0] != '-' || c == 's' || c == 'c'))
		size += 1;
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
		size += (c == 'o') ? 1 : 2;
	if (c == 'f')
		size += p->preci + ft_strnlen(res, '.');
	else if (c == 's' || c == 'c')
		p->preci > len ? (size += len) : (size += p->preci);
	else
		p->preci > len ? (size += p->preci) : (size += len);
	if (size < p->min)
		size = p->min;
	if (!(res2 = ft_strnew(size)))
		return (0);
	res2 = ft_memset(res2, '?', size);
	printf("res2 %s\n", res2);
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
	else
		n = (long long)(va_arg(p->va, int));
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
	else
		u = (unsigned long long)(va_arg(p->va, int));
	return (u);
}
