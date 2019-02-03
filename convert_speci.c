/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_speci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:52:54 by scoron            #+#    #+#             */
/*   Updated: 2019/01/31 15:01:30 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cs_int(t_ftp *p, char c)
{
	char	*res;
	char	*res2;

	p->val = c == 'd' || c == 'D' || c == 'i' ? ft_arg(p) : 0;
	p->u_val = c == 'd' || c == 'D' || c == 'i' ? 0 : ft_uarg(p);
	res = (p->val == 0) ? ft_uitoa(p->u_val) : ft_itoa(p->val);
	if (c == 'o' || c == 'O')
		res = ft_uconvert_base(res, "0123456789", "01234567");
	else if (c == 'X')
		res = ft_uconvert_base(res, "0123456789", "0123456789ABCDEF");
	else if (c == 'x')
		res = ft_uconvert_base(res, "0123456789", "0123456789abcdef");
	res2 = flags_impact(p, res, c);
	free(res);
	buffer(p, ft_strlen(res2), res2);
	free(res2);
}

void		cs_float(t_ftp *p, char c)
{
	long double	flt;
	char		*res;
	char		*res2;

	(void)c;
	flt = p->f & F_LONG2 ? va_arg(p->va, long double) : va_arg(p->va, double);
	res = ft_ditoa(flt);
	res2 = flags_impact(p, res, c);
	free(res);
	buffer(p, ft_strlen(res2), res2);
	free(res2);
}

void		cs_char(t_ftp *p, char c)
{
	char	d[2];
	char	*str;

	d[0] = c == '%' ? '%' : (char)va_arg(p->va, int);
	d[1] = '\0';
	if (d[0] == '\0')
	{
		p->preci = 0;
		str = flags_impact(p, d, c);
		str[ft_strlen(str) - 1] = 0;
		buffer(p, ft_strlen(str), str);
		buffer(p, -1, str);
		write(1, d, 1);
		p->retv++;
	}
	else
	{
		str = flags_impact(p, d, c);
		buffer(p, ft_strlen(str), str);
	}
	free(str);
}

void		cs_str(t_ftp *p, char c)
{
	char	*str;

	(void)c;
	str = va_arg(p->va, char *);
	str = flags_impact(p, str, c);
	buffer(p, ft_strlen(str), str);
	free(str);
}

void		cs_point(t_ftp *p, char c)
{
	uintmax_t		*point;
	char			*res;
	char			*res2;

	(void)c;
	point = (uintmax_t *)va_arg(p->va, void *);
	res = ft_uitoa(*point);
	res = ft_uconvert_base(res, "0123456789", "0123456789abcdef");
	p->f |= F_SHARP;
	res2 = flags_impact(p, res, 'x');
	free(res);
	buffer(p, ft_strlen(res2), res2);
	free(res2);
}
