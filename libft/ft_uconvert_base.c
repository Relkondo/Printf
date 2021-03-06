/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:52:00 by scoron            #+#    #+#             */
/*   Updated: 2019/02/11 15:27:14 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_error_b(char *base)
{
	int i;
	int j;

	i = 0;
	if (base == NULL)
		return (1);
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_find(char *str, char *base, uintmax_t i, int j)
{
	int r;

	if (j == 0)
	{
		r = 0;
		while (base[r] != str[i])
			r++;
		return (r);
	}
	else
	{
		r = 1;
		while (i >= (uintmax_t)j)
		{
			i /= (uintmax_t)j;
			r++;
		}
		return (r);
	}
}

char			*ft_uconvert_base(char *nbr, char *base_from, char *base_to)
{
	char				*res;
	uintmax_t			half_cooked;
	int					count;
	int					bs;

	if (ft_check_error_b(base_to) == 1 || ft_check_error_b(base_from) == 1)
		return (NULL);
	bs = 0;
	half_cooked = ft_uatoi_base(nbr, base_from);
	free(nbr);
	while (base_to[bs] != 0)
		bs++;
	count = ft_find(0, 0, half_cooked, bs);
	res = (char *)malloc(sizeof(char) * (count + 1));
	res[count] = '\0';
	if (half_cooked == 0)
		res[0] = '0';
	while (half_cooked > 0)
	{
		res[count - 1] = base_to[half_cooked % bs];
		half_cooked /= bs;
		count--;
	}
	return (res);
}
