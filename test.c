/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/03 20:47:12 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*char		*ft_ditoa(long double flt)
{
	char			*res;
	int				j;
	long double		tmp;
	int				i;

	i = (flt < 0) ? 1 : 0;
	flt < 1 && flt > -1 ? i++ : 0;
	j = 0;
	tmp = flt > 0 ? flt : -flt;
	while ((long long)tmp && ++i)
		tmp /= 10;
	tmp = flt > 0 ? flt : -flt;
	if (!(res = malloc(sizeof(char) * (8 + i))))
		return (0);
	res[7 + i] = '\0';
	while ((tmp = tmp - (long long)tmp) && ++j < 7)
	{
		tmp *= 10;
		res[i + j] = '0' + (long long)tmp;
	}
	if (flt != (long long)flt)
		res[i] = '.';
	tmp = flt > 0 ? flt : -flt;
	while ((long long)tmp)
	{
		res[--i] = '0' + (long long)tmp % 10;
		tmp /= 10;
	}
	res[0] = i == 0 ? res[0] : '-';
	return (res);
}*/

static void		ldtoa_fill(double n, t_printf *p, long value, int b)
{
	int		len;
	char	s[48];

	p->c = 'a' - 10 - ((p->f & F_UPCASE) >> 1);
	len = p->printed - 1 - p->preci;
	while (p->preci--)
	{
		s[len + p->preci + 1] = value % b + ((value % b < 10) ? '0' : p->c);
		value /= b;
	}
	s[len] = '.';
	value = (long)(n < 0 ? -n : n);
	while (++p->preci < len)
	{
		s[len - p->preci - 1] = value % b + ((value % b < 10) ? '0' : p->c);
		value /= b;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	if (b == 16 && (p->len += 2))
		buffer(p, "0x", 2);
	buffer(p, s, p->printed);
}

void			pf_putdouble(t_printf *p)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(p->ap, double);
	(p->f & F_ZERO) ? p->preci = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->preci = 7;
	len = 1;
	tmp = (long)(n < 0 ? -n : n);
	while (tmp && ++len)
		tmp /= 10;
	p->printed = p->preci + len + ((n < 0) ? 1 : 0);
	decimal = ft_dabs(n);
	decimal = (decimal - (long)(ft_dabs(n))) * ft_pow(10, p->preci + 1);
	decimal = ((long)decimal % 10 > 4) ? decimal / 10 + 1 : decimal / 10;
	value = (long)decimal;
	ldtoa_fill(n, p, value, 10);
}

//printf("tmp : %Lf, long tmp : %lld, soustrac : %Lf, i : %d, j : %d, res : %c\n", tmp, (long long)tmp, (tmp - (long long)tmp), i, j, res[i]);
int		main(void)
{
	char	*res;
	int  k = 30;
	double f = 12346.3456;
	double g = 10.56;
	int i = 0;

	res = ft_ditoa(f);
	printf("float : %.12f, dec : %d, i : %d, res : %s", f, k, i, res);
	return (0);
}
