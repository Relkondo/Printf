/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:24:04 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 17:47:20 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

# define BUF_SIZE 100
# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_WILDCARD		(1 << 5)
# define F_UPCASE		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_LONG			(1 << 8)
# define F_LONG2		(1 << 9)
# define F_CHAR			(1 << 10)

typedef struct		s_ftp
{
	char			*format;
	va_list			va;
	char			*buf;
	int				len_buf;
	int				n;
	int				f;
	size_t			preci;
	int				min;
	int				i;
	int				retv;
}					t_ftp;

void				parse_options(t_ftp *p);
void				buffer(t_ftp *p, int n, char *str);
void				cs_int(t_ftp *p, char c);
void				cs_char(t_ftp *p, char c);
void				cs_str(t_ftp *p, char c);
int					ft_printf(char *format, ...);
void				flag_zero(t_ftp *p, char *res2);
void				flag_preci(t_ftp *p, char *res, char *res2, char c);
char				*calculate_size(t_ftp *p, char *res, char c);

#endif
