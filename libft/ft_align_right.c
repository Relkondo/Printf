/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:05:50 by scoron            #+#    #+#             */
/*   Updated: 2019/01/17 13:44:45 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_align_right(char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (len - i > 0 && str[len - i - 1] == ' ')
		i++;
	while (--len - i >= 0)
		str[len] = str[len - i];
	while (i)
		str[i--] = ' ';
}
