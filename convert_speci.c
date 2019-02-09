/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_speci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:52:54 by scoron            #+#    #+#             */
/*   Updated: 2019/02/09 20:13:22 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cs_int(t_ftp *p, char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
	{
		p->val = ft_arg(p);
		p->size = size_nu(p, p->val);
		print_nu(p, p->val);
	}
	else
	{
		p->u_val = ft_uarg(p);
		p->size = size_ba(p, p->u_val, c);
		if (c == 'o' || c == 'O')
			print_ba(p, p->u_val, "01234567", c);
		else if (c == 'X')
			print_ba(p, p->u_val, "0123456789ABCDEF", c);
		else if (c == 'x')
			print_ba(p, p->u_val, "0123456789abcdef", c);
		else
			print_ba(p, p->u_val, "0123456789", c);
	}
}

void		cs_float(t_ftp *p, char c)
{
	long double	flt;
	char		*res;
	char		*res2;

	(void)c;
	flt = p->f & F_LONG2 ? va_arg(p->va, long double) : va_arg(p->va, double);
	p->f & F_PRECI ? 0 : (p->preci = 6);
	res = ft_dtoa(flt, p);
	p->f & F_PRECI && p->preci == 0 ? 0 : (p->preci += 1);
	res2 = flags_impact(p, res, c);
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
