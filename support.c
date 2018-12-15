/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2018/12/15 21:26:26 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		cs_nbr(t_ftp *p, char c)
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
		buffer(p, ft_strlen(res), res);
}
