/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/01/21 16:22:23 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int  k = 0;
	long long	 j = 4294967296;
	char *str = "Bijour";
	char c = 'A';
	printf("dec : %hhd, octal : %0o, hxdec : %llx, char : %5c, et le str : %.3s\n", c, k, j, c, str);
	ft_printf("dec : %hhd, octal : %0o, hxdec : %llx, char : %5c, et le str : %.3s\n", c, k, j, c, str);

	return (0);
}
