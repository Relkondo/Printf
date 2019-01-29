/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:24:04 by scoron            #+#    #+#             */
/*   Updated: 2019/01/23 19:42:16 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

# define BUF_SIZE 200
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
# define F_INTMAX		(1 << 11)
# define F_PRECI		(1 << 12)


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
	intmax_t		val;
	uintmax_t		u_val;
}					t_ftp;

void				parse_options(t_ftp *p);
void				buffer(t_ftp *p, int n, char *str);
void				cs_int(t_ftp *p, char c);
void				cs_char(t_ftp *p, char c);
void				cs_str(t_ftp *p, char c);
void				cs_point(t_ftp *p, char c);
int					ft_printf(char *format, ...);
void				flag_zero(t_ftp *p, char *res2, char c);
void				flag_preci(t_ftp *p, char *res, char *res2, char c);
char				*calculate_size(t_ftp *p, char *res, char c);
uintmax_t			ft_uarg(t_ftp *p);
intmax_t			ft_arg(t_ftp *p);
char				*flags_impact(t_ftp *p, char *res, char c);

#endif
