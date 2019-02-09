/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/09 21:35:28 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int  k = 0;
	char *str = "Bijour";
	char c = 'A';
	double f = 10.9999;

	printf("float : %#.0f, dec : %d, octal : %0o, hxdec p : %5.x, %5.0x intmax : %jd, char : %c, et le str : %s\n\n", f, k, k, k, k, -922337203685477580, c, "abc");
	ft_printf("float : %#.0f, dec : %d, octal : %0o, hxdec p : %5.x, %5.0x intmax : %jd, char : %c, et le str : %s\n\n", f, k, k, k, k, -922337203685477580, c, "abc");
	return (0); 
}
