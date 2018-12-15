/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:53:07 by scoron            #+#    #+#             */
/*   Updated: 2018/12/15 23:38:22 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "ft_printf.h"

int		main(void)
{
	int  k = 16;
	char *str = "Bijour";
	char c = 'A';
	//ft_printf("%% dec : %d, octal : %o, hxdec : %x, char : %c, et le str : %s\n", k, k, k, c, str);
	printf("%% dec : %d, octal : %9o, hxdec : %x, char : %c, et le str : %s\n", k, k, k, c, str);

	return (0);
}
