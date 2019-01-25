/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:58:12 by scoron            #+#    #+#             */
/*   Updated: 2019/01/23 19:55:26 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*flags_impact(t_ftp *p, char *res, char c)
{
	char	*res2;

	res2 = calculate_size(p, res, c);
	p->i = 0;
	if (((p->f & F_SPACE) || (p->f & F_PLUS)) && res[0] != '-' && c != 's' && c != 'c' && c != '%')
		res2[p->i++] = (p->f & F_PLUS) ? '+' : ' ';
	if ((c == 'x' || c == 'X' || c == 'o') && (p->f & F_SHARP))
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
	int j;

	while (c != 's' && c != 'f' && c != 'c' && c != 'p'
			&& p->preci > 0 && p->preci-- > ft_strlen(res))
		res2[p->i++] = '0';
	j = -1;
	while (res[++j] && res2[p->i + j])
		res2[p->i + j] = res[j];
	p->i += j;
	if (c == 'f' && (j = ft_strchri(res, '.')) == -1 && p->preci > 0
			&& res2[p->i] && res2[++p->i])
		res2[p->i] = '.';
	j++;
	while (c == 'f' && p->preci-- > (ft_strlen(res) - j)
			&& res2[p->i] && res2[++p->i])
		res2[p->i] = '0';
	while (res2[p->i])
		res2[p->i++] = ' ';
}

void	flag_zero(t_ftp *p, char *res2, char c)
{
	int i;

	ft_align_right(res2);
	i = p->f & F_SPACE ? 0 : -1;
	while (p->f & F_ZERO && res2[++i] == ' ')
		res2[i] = '0';
	if (res2[i] == '+' && c != 's' && c != 'c')
	{
		res2[0] = '+';
		res2[i] = '0';
	}
	if (res2[i + 1] == 'x' && c != 's' && c != 'c' && p->u_val != 0)
	{
		res2[1] = 'x';
		res2[i + 1] = '0';
	}
}
