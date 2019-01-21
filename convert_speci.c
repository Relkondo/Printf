/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_speci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:52:54 by scoron            #+#    #+#             */
/*   Updated: 2019/01/21 16:50:20 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cs_int(t_ftp *p, char c)
{
	long long			n;
	unsigned long long	u;
	char				*res;

	n = (c == 'd' || c == 'D' || c == 'i') ? ft_arg(p) : 0;
	u = (c == 'd' || c == 'D' || c == 'i') ? 0 : ft_uarg(p);
	res = (c == 'd' || c == 'D' || c == 'i') ? ft_itoa(n) : ft_uitoa(u);
	//printf("res : %s, n : %lld, u : %llu\n", res, n, u);
	if (c == 'o' || c == 'O')
		res = ft_uconvert_base(res, "0123456789", "01234567");
	else if (c == 'X')
		res = ft_uconvert_base(res, "0123456789", "0123456789ABCDEF");
	else if (c == 'x')
		res = ft_uconvert_base(res, "0123456789", "0123456789abcdef");
	//printf("res : %s\n", res);
	res = flags_impact(p, res, c);
	//printf("res : %s\n", res);
	buffer(p, ft_strlen(res), res);
}

void		cs_char(t_ftp *p, char c)
{
	char	d[2];
	char	*str;

	d[0] = (char)va_arg(p->va, int);
	d[1] = '\0';
	str = flags_impact(p, d, c);
	buffer(p, ft_strlen(str), str);
}

void		cs_str(t_ftp *p, char c)
{
	char	*str;

	(void)c;
	str = va_arg(p->va, char *);
	str = flags_impact(p, str, c);
	buffer(p, ft_strlen(str), str);
}