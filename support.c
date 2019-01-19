/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 14:31:49 by scoron           ###   ########.fr       */
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
	if (((p->f & F_PLUS) || (p->f & F_SPACE)) && res[0] != '-')
		size += 1;
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
		size += (c == 'o') ? 1 : 2;
	if (c == 'f')
		size += p->preci + ft_strnlen(res, '.');
	else if (c == 's')
		p->preci > len ? (size += len) : (size += p->preci);
	else
		p->preci > len ? (size += p->preci) : (size += len);
	if (size < p->min)
		size = p->min;
	if (!(res2 = ft_strnew(size)))
		return (0);
	//printf("size : %d\n", size);
	return (res2);
}

char		*flags_impact(t_ftp *p, char *res, char c)
{
	char	*res2;
	int		i;
	int		j;

	res2 = calculate_size(p, res, c);
	i = 0;
	if ((p->f & F_SPACE) && res[0] != '-')
		res2[i++] = (p->f & F_PLUS) ? '+' : ' ';
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
	{
		res2[i++] = '0';
		c != 'o' ? res2[i++] = c : 0 ;
	}
	while (c != 's' && c != 'f' && c != 'c' && c != 'p'
			&& p->preci > 0 && p->preci-- > ft_strlen(res))
		res2[i++] = '0';
	j = -1;
	while (res[++j])
	{
		res2[i + j] = res[j];
	}
	//printf("res : %s res2 : %s\n", res, res2);
	i += j;
	if (c == 'f' && (j = ft_strchri(res, '.')) == -1 && p->preci > 0
			&& res2[i] && res2[++i])
		res2[i] = '.';
	j++;
	while (c == 'f' && p->preci-- > (ft_strlen(res) - j) && res2[i] && res2[++i])
		res2[i] = '0';
	while (res2[++i] && (!(p->f | F_ZERO) || (p->f | F_MINUS)))
		res2[i] = ' ';
	if (p->f | F_MINUS)
		ft_align_right(res2);
	return (res2);
}

//doit prendre en compte les flags hhll (et L pour f)

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
//	printf("res : %s\n", res);
	res = flags_impact(p, res, c);
//	printf("res : %s\n", res);
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
