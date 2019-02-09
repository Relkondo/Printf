/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:05:45 by scoron            #+#    #+#             */
/*   Updated: 2019/02/09 20:18:04 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_nu(t_ftp *p, intmax_t n)
{
	int			size;
	int			len;
	int			pre;

	size = p->f & F_SPACE || p->f & F_PLUS || p->val < 0 ? 1 : 0;
	len = 1;
	pre = p->preci;
	while (n / 10 != 0 && ++size && ++len)
		n /= 10;
	while (pre-- > len)
		size++;
	return (size);
}

int		size_ba(t_ftp *p, uintmax_t n, char c)
{
	int			size;
	int			bs;
	int			len;
	int			pre;

	size = p->f & F_PLUS ? 1 : 0;
	pre = p->preci;
	bs = 10;
	len = 1;
	if (c == 'o' || c == 'x' || c == 'X')
		bs = c == 'o' ? 8 : 16; 
	if (p->f & F_SHARP && (c == 'o' || c == 'x' || c == 'X'))
		size += c == 'o' ? 1 : 2;
	while ((n / bs) != 0 && ++size && ++len)
		n /= bs;
	//printf("n : %ju, size : %d, bs : %d\n", n, size, bs);
	while (pre-- > len)
		size++;
	return (size);
}
