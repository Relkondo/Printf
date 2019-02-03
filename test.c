/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/01 18:03:30 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char		*ft_ditoa(long double flt)
{
	char			*res;
	int				j;
	long double		tmp;
	int				i;

	i = (flt < 0) ? 1 : 0;
	flt < 1 && flt > -1 ? i++ : 0;
	j = 0;
	tmp = flt > 0 ? flt : -flt;
	while ((long long)tmp && ++i)
		tmp /= 10;
	tmp = flt > 0 ? flt : -flt;
	tmp = flt > 0 ? flt : -flt;
	if (!(res = malloc(sizeof(char) * (8 + i))))
		return (0);
	res[7 + i] = '\0';
	while ((tmp = tmp - (long long)tmp) && ++j < 7)
	{
		tmp *= 10;
		res[i + j] = '0' + (long long)tmp;
	}
	//if (res[i + j] <= 
	if (flt != (long long)flt)
		res[i] = '.';
	tmp = flt > 0 ? flt : -flt;
	while ((long long)tmp)
	{
		res[--i] = '0' + (long long)tmp % 10;
		tmp /= 10;
	}
	res[0] = i == 0 ? res[0] : '-';
	return (res);
}

	//printf("tmp : %Lf, long tmp : %lld, soustrac : %Lf, i : %d, j : %d, res : %c\n", tmp, (long long)tmp, (tmp - (long long)tmp), i, j, res[i]);
int		main(void)
{
	char	*res;
	int  k = 30;
	double f = 12346.984783;
	double g = 10.56;
	int i = 0;

	res = ft_ditoa(f);
	printf("float : %f, dec : %d, i : %d, res : %s", f, k, i, res);
	return (0);
}
