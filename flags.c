/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:58:12 by scoron            #+#    #+#             */
/*   Updated: 2019/02/09 23:15:35 by scoron           ###   ########.fr       */
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
	if (p->val == 0 && p->u_val == 0 && c != '%' && c != 'f')
	{
		p->f & F_PRECI && p->preci == 0 ? *res = 0 : 0;
		p->f & F_SHARP && c != 'o' ? p->f ^= F_SHARP : 0;
	}
	res2 = calculate_size(p, res, c);
	p->i = 0;
	if (((p->f & F_SPACE) || (p->f & F_PLUS))
			&& res[0] != '-' && c != 's' && c != 'c' && c != '%' && c != 'u')
		res2[p->i++] = (p->f & F_PLUS) ? '+' : ' ';
	//printf("res : %s, res2 : %s\n", res, res2);
	flag_preci(p, res, res2, c);
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
	j = -1;
	while (res[++j] && res2[p->i + j]
			 && (c != 's' || !(p->f & F_PRECI) || pre-- > 0))
		res2[p->i + j] = res[j];
	p->i += j;
	//printf("res : %s, res2 : %s, i : %d, len : %zu, j : %d, pre : %zu, preci : %zu\n", res, res2, p->i, len, j, pre, p->preci);
	while (res2[p->i])
		res2[p->i++] = ' ';
}

void	flag_zero(t_ftp *p, char *res2, char c)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	if (!(p->f & F_MINUS))
		ft_align_right(res2);
	i = p->f & F_SPACE ? 0 : -1;
	while (p->f & F_PRECI && i < (int)(ft_strlen(res2) - p->preci) && c != 'f')
		i++;
	while (p->f & F_ZERO && !(p->f & F_MINUS) && res2[++i] == ' ')
		res2[i] = '0';
	i < 0 ? i = 0 : 0;
	while (res2[i] == '0')
		i++;
	//printf("res2 : %s, i : %d, preci : %zu\n", res2, i, p->preci);
	if ((res2[i] == '+' || res2[i] == '-') && c != 's' && c != 'c')
	{
		tmp = res2[i];
		res2[i] = '0';
		while (res2[j] == ' ')
			j++;
		res2[j] = tmp;
	}
	if ((res2[i] == 'x' || res2[i] == 'X') && c != 's' && c != 'c' && p->u_val != 0)
	{
		tmp = res2[i];
		res2[i] = '0';
		res2[1] = tmp;
	}
}
