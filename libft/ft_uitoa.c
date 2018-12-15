/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2018/12/15 21:01:43 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putint(char *res, unsigned int n, size_t len)
{
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

char		*ft_uitoa(unsigned int n)
{
	char			*res;
	size_t			len;
	unsigned int	k;

	len = 1;
	k = n;
	while (k / 10 != 0)
	{
		len++;
		k /= 10;
	}
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	res[len] = 0;
	res = ft_putint(res, n, len);
	return (res);
}
