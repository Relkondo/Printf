/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:58:12 by scoron            #+#    #+#             */
/*   Updated: 2019/01/31 14:22:55 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*flags_impact(t_ftp *p, char *res, char c)
{
	char	*res2;

	res2 = 0;
	if (c == 's' && !(res))
		return (ft_strdup("(null)"));
	if (p->val == 0 && p->u_val == 0 && c != '%')
	{
		p->f & F_PRECI && p->preci == 0 ? *res = 0 : 0;
		p->f & F_SHARP && c != 'o' ? p->f ^= F_SHARP : 0;
	}
	res2 = calculate_size(p, res, c);
	p->i = 0;
	if (((p->f & F_SPACE) || (p->f & F_PLUS))
			&& res[0] != '-' && c != 's' && c != 'c' && c != '%' && c != 'u')
		res2[p->i++] = (p->f & F_PLUS) ? '+' : ' ';
	if ((c == 'x' || c == 'X' || c == 'o') && p->f & F_SHARP)
	{
		res2[p->i++] = '0';
		c != 'o' ? res2[p->i++] = c : 0;
	}
	flag_preci(p, res, res2, c);
	if (!(p->f & F_MINUS))
		flag_zero(p, res2, c);
	return (res2);
}

void	flag_preci(t_ftp *p, char *res, char *res2, char c)
{
	int		j;
	size_t	len;
	size_t	pre;

	len = ft_strlen(res);
	pre = p->preci;
	while (c != 's' && c != 'f' && c != 'c' && c != 'p'
			&& pre > 0 && pre-- > len)
		res2[p->i++] = '0';
	j = -1;
	while (res[++j] && res2[p->i + j]
			&& (c != 's' || !(p->f & F_PRECI) || pre-- > 0))
		res2[p->i + j] = res[j];
	p->i += j;
	if (c == 'f' && (j = ft_strchri(res, '.')) == -1 && pre > 0
			&& res2[p->i] && res2[++p->i])
		res2[p->i] = '.';
	j++;
	while (c == 'f' && pre-- > (len - j)
			&& res2[p->i] && res2[++p->i])
		res2[p->i] = '0';
	while (res2[p->i])
		res2[p->i++] = ' ';
}

void	flag_zero(t_ftp *p, char *res2, char c)
{
	int		i;
	char	tmp;

	ft_align_right(res2);
	i = p->f & F_SPACE ? 0 : -1;
	while (p->f & F_PRECI && i < (int)(ft_strlen(res2) - p->preci))
		i++;
	while (p->f & F_ZERO && res2[++i] == ' ')
		res2[i] = '0';
	i < 0 ? i = 0 : 0;
	while (res2[i] == '0')
		i++;
	if ((res2[i] == '+' || res2[i] == '-') && c != 's' && c != 'c')
	{
		tmp = res2[i];
		res2[i] = '0';
		res2[0] = tmp;
	}
	if (res2[i] == 'x' && c != 's' && c != 'c' && p->u_val != 0)
	{
		res2[i] = '0';
		res2[1] = 'x';
	}
}
