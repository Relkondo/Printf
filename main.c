/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/03 21:52:59 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int  k = 0;
	char *str = "Bijour";
	char c = 'A';
	double f = 10.3256465315634;

	printf("float : %f, dec : %jx, octal : %0o, hxdec p  : %.x, %.0x intmax : %jd, char : %c, et le str : %s\n", f, 4294967295, k, 0, 0, -922337203685477580, c, "abc");
	ft_printf("float : %f, dec : %jx, octal : %0o, hxdec p : %.x, %.0x intmax : %jd, char : %c, et le str : %s\n", f, 4294967295, k, 0, 0, -922337203685477580, c, "abc");
	rminett
	return (0);
}
