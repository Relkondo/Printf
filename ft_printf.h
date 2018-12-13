/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:24:04 by scoron            #+#    #+#             */
/*   Updated: 2018/12/13 19:15:58 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"

#define BUFFER_SIZE 42

typedef struct		s_ftp
{
	char			*format;
	va_list			va;
}					t_ftp;

#endif
