/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:07:22 by scoron            #+#    #+#             */
/*   Updated: 2018/12/15 19:22:37 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	cs_not_found(t_ftp *p, char c)
{
	p->len_buf++;
	p->len_buf--;
	if (c == 'A')
		return ;
	return ;
}

static inline void	fill_func(void (**func)(t_ftp *p, char c))
{
	int i;

	i = -1;
	while (++i < 257)
		func[i] = &cs_not_found;
	func['d'] = &cs_nbr;
	func['i'] = &cs_nbr;
	func['D'] = &cs_nbr;
	func['b'] = &cs_nbr;
	func['B'] = &cs_nbr;
	func['o'] = &cs_nbr;
	func['O'] = &cs_nbr;
	func['u'] = &cs_nbr;
	func['U'] = &cs_nbr;
	func['x'] = &cs_nbr;
	func['X'] = &cs_nbr;
	func['f'] = &cs_nbr;
	func['F'] = &cs_nbr;
	func['S'] = &cs_nbr;
	func['c'] = &cs_nbr;
	func['C'] = &cs_nbr;
	func['n'] = &cs_nbr;
	func['m'] = &cs_nbr;
	func['p'] = &cs_nbr;
}

void				parse_options(t_ftp *p)
{
	static void (*func[256])(t_ftp *p, char c);

	if (!func[0])
		fill_func(func);
	(p->format)++;
	func[(int)*(p->format)](p, *(p->format));
}
