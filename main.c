/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/02/11 15:14:02 by scoron           ###   ########.fr       */
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
	int ret;

ret = ft_printf("cc%#.4X et %#0012x %04hX !!\n", 0xaef, 0xe, (unsigned short)0);
printf("ret ft : %d\n", ret);
ret = printf("cc%#.4X et %#0012x %04hX !!\n", 0xaef, 0xe, (unsigned short)0);
printf("ret : %d\n", ret);
ret = ft_printf("%0#10.0x\n", 0);
printf("ret ft : %d\n", ret);
ret = printf("%0#10.0x\n", 0);
printf("ret : %d\n", ret);
ret = ft_printf("%.2s\n", NULL);
printf("ret ft : %d\n", ret);
ret = printf("%.2s\n", NULL);
printf("ret : %d\n", ret);
ret = ft_printf("u%4.2ss %-1.s\n %---5.3s \n", "coco", NULL, "yooo");
printf("ret ft : %d\n", ret);
ret = printf("u%4.2ss %-1.s\n %---5.3s \n", "coco", NULL, "yooo");
printf("ret : %d\n", ret);
ret = ft_printf("%p\n", NULL);
printf("ret ft : %d\n", ret);
ret = printf("%p\n", NULL);
printf("ret : %d\n", ret);
ret = ft_printf("%----24p et hello %2p %12p\n", &ret, &main, NULL);
printf("ret ft : %d\n", ret);
ret = printf("%----24p et hello %2p %12p\n", &ret, &main, NULL);
printf("ret : %d\n", ret);

	return (0); 
}
