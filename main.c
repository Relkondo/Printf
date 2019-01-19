/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 18:41:55 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int  k = 1600;
	char *str = "Bijour";
	char c = 'A';
	ft_printf("%% dec : %hhd, octal : %0o, hxdec : %#08x, char : %c, et le str : %s\n", c, k, k, c, str);
	printf("%% dec : %hhd, octal : %0o, hxdec : %#08x, char : %c, et le str : %s\n", c, k, k, c, str);

	return (0);
}
