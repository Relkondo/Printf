/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/01/21 19:54:50 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int  k = 0;
	char *str = "Bijour";
	char c = 'A';
	printf("dec : %hhd, octal : %0o, hxdec : %x, intmax : %jd, char : %c, et le str : %s\n", c, k, -42, -9223372036854775807, c, str);
	ft_printf("dec : %hhd, octal : %0o, hxdec : %x, intmax : %jd, char : %c, et le str : %s\n", c, k, -42, -9223372036854775807, c, str);

	return (0);
}
