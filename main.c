/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/10 00:12:01 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	/*int  k = 0;
	char *str = "Bijour";
	char c = 0;
	double f = 34.46;

	printf("float : %#2f, dec : %d, octal : %0o, hxdec p : %5.x, %5.0x intmax : %jd, char : %c, et le str : %s\n\n", f, k, k, k, k, -922337203685477580, c, str);
	ft_printf("float : %#2f, dec : %d, octal : %0o, hxdec p : %5.x, %5.0x intmax : %jd, char : %c, et le str : %s\n\n", f, k, k, k, k, -922337203685477580, c, str);*/
		int		nb;
	char	c;
	nb = 0;
	c = 'W';
	dprintf(2,"%5p\n", &nb);
	dprintf(2,"%-15p\n", &nb);
	dprintf(2,"%-5p\n", &nb);
	dprintf(2,"%42p\n", &nb);
	dprintf(2,"%-18p\n", &nb);
	dprintf(2,"%42p\n", &nb);
	dprintf(2,"%5p\n", &c);
	dprintf(2,"%-15p\n", &c);
	dprintf(2,"%-5p\n", &c);
	dprintf(2,"%42p\n", &c);
	dprintf(2,"%-18p\n", &c);
	dprintf(2,"%42p\n", &c);

	ft_printf("%5p\n", &nb);
	ft_printf("%-15p\n", &nb);
	ft_printf("%-5p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%-18p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%5p\n", &c);
	ft_printf("%-15p\n", &c);
	ft_printf("%-5p\n", &c);
	ft_printf("%42p\n", &c);
	ft_printf("%-18p\n", &c);
	ft_printf("%42p\n", &c);

	return (0); 
}
