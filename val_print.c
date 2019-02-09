/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/02/09 20:43:09 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		putint(char *res, intmax_t n, size_t len)
{
	uintmax_t	tmp;

	tmp = n < 0 ? -n : n;
	n == 0 ? res[0] = '0' : 0;
	res[len] = 0;
	while (tmp != 0)
	{
		res[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
}

void		print_nu(t_ftp *p, intmax_t n)
{
	char		res[21];
	size_t		len;
	int			pre;
	int			i;

	i = 0;
	len = 1;
	pre = p->preci;
	if (!(p->f & F_MINUS))
		p->f & F_ZERO && !(p->f & F_PRECI) ? padding(p, '0') : padding(p, ' ');
	p->f & F_SPACE && n >= 0 ? buffer(p, 1, " ") : 0;
	p->f & F_PLUS && n >= 0 ? buffer(p, 1, "+") : 0;
	n < 0 ? buffer(p, 1, "-") : 0;
	while (n / 10 != 0 && ++len)
		n /= 10;
	while (pre-- > (int)len)
		buffer(p, 1, "0");
	putint(res, p->val, len);
	p->val == 0 && p->f & F_PREZERO ? 0 : buffer(p, (int)len, res);
	if (p->f & F_MINUS)
		padding(p, ' ');
}

void		uputint_base(char *res, uintmax_t n, char *base_to)
{
	int					count;
	int					bs;
	uintmax_t			tmp;

	bs = 0;
	count = 1;
	tmp = n;
	while (base_to[bs])
		bs++;
	while ((tmp /= bs))
		count++;
	//printf("n : %jd, res : %s, bs : %d\n", n, res, bs);
	res[count] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[count - 1] = base_to[n % bs];
		n /= bs;
		count--;
	}
}

void		print_ba(t_ftp *p, uintmax_t n, char *base, char c)
{
	char		res[23];
	int			pre;
	size_t		len;
	int			i;

	i = 0;
	pre = p->preci;
	if (!(p->f & F_MINUS))
		p->f & F_ZERO && !(p->f & F_PRECI) ? padding(p, '0') : padding(p, ' ');
	p->f & F_PLUS ? buffer(p, 1, "+") : 0;
	p->f & F_SHARP && c == 'o' ? buffer(p, 1, "0") : 0;
	p->f & F_SHARP && c == 'x' ? buffer(p, 2, "0x") : 0;
	p->f & F_SHARP && c == 'X' ? buffer(p, 2, "0X") : 0;
	uputint_base(res, n, base);
	len = ft_strlen(res);
	while (pre-- > (int)len)
		buffer(p, 1, "0");
	p->u_val == 0 && p->f & F_PREZERO ? 0 : buffer(p, (int)len, res);
	if (p->f & F_MINUS)
		padding(p, ' ');
}
