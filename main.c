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
	//int  k = 0;
	//char *str = "Bijour";
	//char c = 'A';
	//double f = 34.46;

	//printf("float : %#2f, dec : %d, octal : %0o, hxdec p : %5.x, %5.0x intmax : %jd, char : %c, et le str : %s\n\n", f, k, k, k, k, -922337203685477580, c, "abc");
	//ft_printf("float : %#2f, dec : %d, octal : %0o, hxdec p : %5.x, %5.0x intmax : %jd, char : %c, et le str : %s\n\n", f, k, k, k, k, -922337203685477580, c, "abc");
	int	nb = 0;
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("test o:%o\n", nb);
	ft_printf("hash:%#o\n", nb);
	ft_printf("precision / grande:%.5o\n", nb);
	ft_printf("Prec + hash / grande:%#.5o\n", nb);
	ft_printf("Prec + hash / petite:%#.1o\n", nb);
	ft_printf("Prec + 0:%0.5o\n", nb);
	ft_printf("Prec + minus:%-.5o\n", nb);
	ft_printf("Size:%5o\n", nb);
	ft_printf("size + prec:%7.3o\n", nb);
	ft_printf("size + minus:%-5o\n", nb);
	ft_printf("size + zero:%05o\n", nb);
	ft_printf("size + zero + hash:%#05o\n", nb);
	ft_printf("size + zero + prec:%05.3o\n", nb);
	ft_printf("size + minus + prec:%-5.3o\n", nb);
	ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);

	printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("atest o:%o\n", nb);
	printf("hash:%#o\n", nb);
	printf("precision / grande:%.5o\n", nb);
	printf("Prec + hash / grande:%#.5o\n", nb);
	printf("Prec + hash / petite:%#.1o\n", nb);
	printf("Prec + 0:%0.5o\n", nb);
	printf("Prec + minus:%-.5o\n", nb);
	printf("Size:%5o\n", nb);
	printf("size + prec:%7.3o\n", nb);
	printf("size + minus:%-5o\n", nb);
	printf("size + zero:%05o\n", nb);
	printf("size + zero + hash:%#05o\n", nb);
	printf("size + zero + prec:%05.3o\n", nb);
	printf("size + minus + prec:%-5.3o\n", nb);
	printf("size + hash + zero + prec:%#05.3o\n", nb);
	printf("size + hash + zero + prec:%0#5.3o\n", nb);
	printf("size + hash + minus + prec:%-#7.3o\n", nb);
	return (0); 
}
