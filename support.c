/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2018/12/21 22:29:45 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			calculate_size(t_ftp *p, char *res, char c)
{
	char	*res2;
	int		size;
	int		len;

	len = ft_strlen(res);
	size = 0;
	if (((p->f & F_PLUS) || (p->f & F_SPACE)) && res[0] != '-')
		size += 1;
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
		size += (c == 'o') ? 1 : 2;
	if (c == 's' && p->preci < len)
		size += p->preci;
	else if (c == 'f')
		size += p->preci + ft_strnlen(res, '.');
	else if (p->preci > len)
		size += p->preci;
	else
		size += len;
	if (size < p->min)
		size = p->min;
	if (!(res2 = ft_strnew(size)))
		return (0);
	return (res2);
}

char		*flags_impact(t_ftp *p, char *res, char c)
{
	char	*res2;
	size_t	len;
	int		i;

	len = ft_strlen(res);
	res2 = calculate_size(p, res, c);
	i = 0;
	if ((p->f & F_SPACE) && res[0] != '-')
		res2[i++] = (p->f & F_PLUS) ? '+' : ' ';
	if (c == 'o' && (p->f & F_SHARP))
		res2[i++] = '0';
	if ((c == 'x' || c == 'X') && (p->f & F_SHARP))
	{
		res2[i++] = '0';
		res2[i++] = c;
	}
	while (p->preci > len && c != 's' && c != 'f' && c != 'c' && c != 'p')
	{
		res2[i++] = '0';
		p->preci--;
	}
	while (len--)
		res2[i + len] = res[len];
	i += ft_strlen(res);

//manque le '.' potentiel et les chiffres apres decimal, plus la taille minimum si s, plus les zeros, etc 
	if (c == 's' && p->preci < len)
		size += p->preci;
	else if (c == 'f')
		size += p->preci + ft_strnlen(res, '.');
	else if (p->preci > len)
		size += p->preci;
	else
		size += len;
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
