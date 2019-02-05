/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/05 22:16:57 by scoron           ###   ########.fr       */
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

	//dprintf(2, "float : %#.0f, dec : %14jx, octal : %0o, hxdec p : %.x, %.0x intmax : %jd, char : %c, et le str : %s\n\n", f, 4294967295, k, 0, 0, -922337203685477580, c, "abc");
	//ft_printf("float : %#.0f, dec : %14jx, octal : %0o, hxdec p : %.x, %.0x intmax : %jd, char : %c, et le str : %s\n\n", f, 4294967295, k, 0, 0, -922337203685477580, c, "abc");
	double		nb;
		nb = -12547.58;
	ft_printf("space:% f\n", nb);
	dprintf(2, "space:% f\n", nb);
	ft_printf("plus:%+f\n", nb);
	dprintf(2, "plus:%+f\n", nb);
	ft_printf("hash:%#f\n", nb);
	dprintf(2, "hash:%#f\n", nb);
	ft_printf("precision:%.2f\n", nb);
	dprintf(2, "precision:%.2f\n", nb);
	ft_printf("big prec:%.14f\n", nb);
	dprintf(2, "big prec:%.14f\n", nb);
	ft_printf("precision + hash:%#.0f\n", nb);
	dprintf(2, "precision + hash:%#.0f\n", nb);
	ft_printf("space + prec:% .5f\n", nb);
	dprintf(2, "space + prec:% .5f\n", nb);
	ft_printf("space + prec + hash:%# .0f\n", nb);
	dprintf(2, "space + prec + hash:%# .0f\n", nb);
	ft_printf("space + prec + hash:% #.0f\n", nb);
	dprintf(2, "space + prec + hash:% #.0f\n", nb);
	ft_printf("Plus + prec / grande:%+.5f\n", nb);
	dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
	ft_printf("Plus + prec / petite:%+.0f\n", nb);
	dprintf(2, "Plus + prec / petite:%+.0f\n", nb);
	ft_printf("Plus + prec + hash:%#+.0f\n", nb);
	dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);
	ft_printf("Prec + 0:%0.5f\n", nb);
	dprintf(2, "Prec + 0:%0.5f\n", nb);
	ft_printf("Prec + minus:%-.5f\n", nb);
	dprintf(2, "Prec + minus:%-.5f\n", nb);
	ft_printf("size:%5f\n", nb);
	dprintf(2, "size:%5f\n", nb);
	ft_printf("size + space:% 5f\n", nb);
	dprintf(2, "size + space:% 5f\n", nb);
	ft_printf("size + plus:%+5f\n", nb);
	dprintf(2, "size + plus:%+5f\n", nb);
	ft_printf("size + space:%# 5f\n", nb);
	dprintf(2, "size + space:%# 5f\n", nb);
	ft_printf("size + plus:%#+5f\n", nb);
	dprintf(2, "size + plus:%#+5f\n", nb);
	ft_printf("size + minus:%-5f\n", nb);
	dprintf(2, "size + minus:%-5f\n", nb);
	ft_printf("size + 0:%05f\n", nb);
	dprintf(2, "size + 0:%05f\n", nb);
	ft_printf("size + 0 + plus:%+05f\n", nb);
	dprintf(2, "size + 0 + plus:%+05f\n", nb);
	ft_printf("size + 0 + plus:%0+5f\n", nb);
	dprintf(2, "size + 0 + plus:%0+5f\n", nb);
	ft_printf("size + 0 + prec:%05.3f\n", nb);
	dprintf(2, "size + 0 + prec:%05.3f\n", nb);
	ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
	dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);
	ft_printf("size + minus + prec:%-5.3f\n", nb);
	dprintf(2, "size + minus + prec:%-5.3f\n", nb);
	ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
	dprintf(2, "size + minus + prec + hash:%-#5.0f\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
	ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
	ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3f\n", nb);
	ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	return (0); 
}
