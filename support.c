/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2018/12/16 00:50:05 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*flags_impact(t_ftp *p, char *res, char c)
{
	int		size;

	size = 0;
	if (((p->f & F_PLUS) || (p->f & F_SPACE)) && res[0] != '-')
		size += 1;
	if (c == 'o' && (p->f & F_SHARP))
		size += 1;
	if ((c == 'x' || c == 'X') && (p->f & F_SHARP))
		size += 2;
	size += (p->preci - ft_strlen(res));
	


}

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
