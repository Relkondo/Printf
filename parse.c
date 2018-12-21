/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:07:22 by scoron            #+#    #+#             */
/*   Updated: 2018/12/21 22:18:01 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parse_flags(t_ftp *p)
{
	while ((p->n = ft_strchri("# +-0", *p->format)) > -1 && ++p->format)
		p->f |= (1 << p->n);
	p->format--;
	while (ft_isdigit(*(p->format)) && ++p->format)
		p->min = 10*(p->min) + (*(p->format) - '0');
	if (*(p->format) = '.' && ++p->format)
		while (ft_isdigit(*(p->format)) && ++p->format)
			p->preci = 10*(p->preci) + (*(p->format) - '0');
	if ((p->n = ft_strchri("hlL", *(p->format))) > -1 && ++p->format)
		p->f |= (1 << (p->n + 7));
	if ((p->n = ft_strchri("lh", *(p->format))) > -1 && ++p->format)
		p->f |= (1 << (p->n + 9));
}

static inline void	cs_not_found(t_ftp *p, char c)
{
	(void)c;
	buffer(p, 1, p->format);
	return ;
}

static inline void	fill_func(void (**func)(t_ftp *p, char c))
{
	int i;

	i = -1;
	while (++i < 257)
		func[i] = &cs_not_found;
	func['d'] = &cs_int;
	func['D'] = &cs_int;
	func['i'] = &cs_int;
	func['o'] = &cs_int;
	func['O'] = &cs_int;
	func['u'] = &cs_int;
	func['U'] = &cs_int;
	func['x'] = &cs_int;
	func['X'] = &cs_int;
	func['c'] = &cs_char;
	func['s'] = &cs_str;

	func['C'] = &cs_char;
	func['S'] = &cs_int;
	func['p'] = &cs_int;
}

void				parse_options(t_ftp *p)
{
	static void (*func[256])(t_ftp *p, char c);

	p->min = 0;
	p->preci = 0;
	parse_flags(t_ftp *p);
	if (!func[0])
		fill_func(func);
	func[(int)*(p->format)](p, *(p->format));
}
