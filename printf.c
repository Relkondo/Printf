/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:20:06 by scoron            #+#    #+#             */
/*   Updated: 2018/12/13 19:16:00 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_ftp		p;

	p.format = format;
	va_start(p.va, format);
	while (*(p.format))
	{
		if (*(p.format) == '%')
			parse_options(&p);
		else
			buffer(&p, 1);
		(p.format)++;
	}
	va_end(p.va);
	buffer(&p, 0);
	return (p.nb);
}
