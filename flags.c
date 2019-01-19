/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:58:12 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 17:44:09 by scoron           ###   ########.fr       */
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
	res2 = ft_memset(res2, '?', size);
	//printf("size : %d\n", size);
	return (res2);
}

void	flag_preci(t_ftp *p, char *res, char *res2, char c)
{
	int j;

	while (c != 's' && c != 'f' && c != 'c' && c != 'p'
			&& p->preci > 0 && p->preci-- > ft_strlen(res))
		res2[p->i++] = '0';
	j = -1;
	while (res[++j])
		res2[p->i + j] = res[j];
	p->i += j;
	if (c == 'f' && (j = ft_strchri(res, '.')) == -1 && p->preci > 0
			&& res2[p->i] && res2[++p->i])
		res2[p->i] = '.';
	j++;
	while (c == 'f' && p->preci-- > (ft_strlen(res) - j) && res2[p->i] && res2[++p->i])
		res2[p->i] = '0';
	while (res2[p->i])
		res2[p->i++] = ' ';
}

void	flag_zero(t_ftp *p, char *res2)
{
	int i;

	ft_align_right(res2);
	i = p->f & F_SPACE ? 0 : -1;
	while (p->f & F_ZERO && res2[++i] == ' ')
		res2[i] = '0';
	if (res2[i] == '+')
	{
		res2[0] = '+';
		res2[i] = '0';
	}
	if (res2[i + 1] == 'x')
	{
		res2[1] = 'x';
		res2[i + 1] = '0';
	}
}
