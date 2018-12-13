/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:38:49 by scoron            #+#    #+#             */
/*   Updated: 2018/12/13 19:15:55 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_print_nbr(int nbp)
{
	if (nbp > 9)
	{
		ft_print_nbr(nbp / 10);
		ft_putchar(nbp % 10 + '0');
	}
	else
		ft_putchar(nbp + '0');
}

void		pf_putnbr(t_ftp *p)
{

	int check;

	check = 0;
	if (n == -2147483648)
	{
		n = -214748364;
		check = 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	pf_print_nbr(n);
	if (check == 1)
		ft_putchar('8');
}
