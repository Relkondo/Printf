/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/01/21 18:53:43 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putint(char *res, intmax_t n, size_t len)
{
	if (n == 0)
		res[0] = '0';
	if (n == -2147483648)
	{
		res[--len] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(intmax_t n)
{
	char		*res;
	size_t		len;
	intmax_t	k;

	len = 1;
	k = n;
	if (n < 0)
		len++;
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
