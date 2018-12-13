/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:07:22 by scoron            #+#    #+#             */
/*   Updated: 2018/12/13 19:15:47 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	not_found(t_ftp *p)
{
	return ;
}

static inline void	fill_func(int (*func)(t_ftp *p))
{
	int i;

	i = -1;
	while (++i < 257)
		func[i] = not_found;
	func['d'] = pf_putnbr;
}

void				parse_options(t_ftp *p)
{
	static void (func[256])(t_ftp *p);

	if (!func)
		fill_func(func);
	(p->format)++;
	func[*(p->format)](p); //rajouter va_arg... en arg
}

