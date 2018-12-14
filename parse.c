/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:07:22 by scoron            #+#    #+#             */
/*   Updated: 2018/12/14 21:36:38 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	not_found(t_ftp *p)
{
	p->len_buf++;
	p->len_buf--;
	return ;
}

static inline void	fill_func(void (**func)(t_ftp *p))
{
	int i;

	i = -1;
	while (++i < 257)
		func[i] = &not_found;
	func['d'] = &pf_itoa;
}

void				parse_options(t_ftp *p)
{
	static void (*func[256])(t_ftp *p);

	if (!func[0])
		fill_func(func);
	(p->format)++;
	func[(int)*(p->format)](p);
}
