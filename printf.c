/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:20:06 by scoron            #+#    #+#             */
/*   Updated: 2018/12/21 20:49:32 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_ftp		p;

	p.format = format;
	p.len_buf = 0;
	p.buf = ft_strnew(BUF_SIZE);
	va_start(p.va, format);
	while (*(p.format))
	{
		if (*(p.format) == '%' && p.format++)
			parse_options(&p);
		else
			buffer(&p, 1, p.format);
		(p.format)++;
	}
	va_end(p.va);
	buffer(&p, -1, 0);
	free(p.buf);
	return (0);
}

void	buffer(t_ftp *p, int n, char *str)
{
	while (n > 0 && BUF_SIZE - p->len_buf >= n)
	{
		p->buf[p->len_buf] = *str;
		str++;
		p->len_buf++;
		n--;
	}
	if (p->len_buf == BUF_SIZE || n < 0 || n > BUF_SIZE - p->len_buf)
	{
		write(1, p->buf, p->len_buf);
		p->len_buf = 0;
	}
	if (n > BUF_SIZE)
		write(1, str, n);
	else if (n > 0)
		buffer(p, n, str);
}
