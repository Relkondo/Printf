/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 18:49:37 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int  k = 0;
	char *str = "Bijour";
	char c = 'A';
	ft_printf("dec : %hhd, octal : %0o, hxdec : %lx, char : %c, et le str : %s\n", c, k, 4294967296, c, str);
	printf("dec : %hhd, octal : %0o, hxdec : %lx, char : %c, et le str : %s\n", c, k, 4294967296, c, str);

	return (0);
}
