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
	int  k = 7;
	int	 j = 10;
	char *str = "Bijour";
	char c = 'A';
	printf("dec : %hhd, octal : %0o, hxdec : %x, char : %c, et le str : %s\n", c, k, j, c, str);
	ft_printf("dec : %hhd, octal : %0o, hxdec : %x, char : %c, et le str : %s\n", c, k, j, c, str);

	return (0);
}
