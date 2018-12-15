/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:24:04 by scoron            #+#    #+#             */
/*   Updated: 2018/12/15 19:17:02 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

#define BUF_SIZE 16

typedef struct		s_ftp
{
	char			*format;
	va_list			va;
	char			*buf;
	int				len_buf;
}					t_ftp;

void				parse_options(t_ftp *p);
void				buffer(t_ftp *p, int n, char *str);
void				cs_nbr(t_ftp *p, char c);
int					ft_printf(char *format, ...);

#endif
