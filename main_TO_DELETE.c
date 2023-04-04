/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_TO_DELETE.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:26:55 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/04/04 14:00:06 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/argument_handlers.c"
#include "./ft_printf/dispatcher.c"
#include "./ft_printf/dispatcher1.c"
#include "./ft_printf/ft_printf.c"
#include "./ft_printf/ft_printf.h"
#include "./ft_printf/lib_ft.c"
#include "./ft_printf/lib_ft1.c"
#include "./ft_printf/printer.c"
#include "./ft_printf/printer_1.c"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		d;
	char	c;
	char	b;
	char	s[4];

	d = 3;
	c = 'j';
	b = '3';
	s[0] = 's';
	s[1] = 'l';
	s[2] = 't';
	s[3] = '\0';
	// printf("Size: %d\n", printf("%d %5c ", d, c));
	// printf("Size: %d\n", ft_printf("%d %5c ", d, c));
	// printf("--------------\n");
	// printf("Size: %d\n", printf("%5.6d %c ", -d, c));
	// printf("Size: %d\n", ft_printf("%5.6d %c ", -d, c));
	// printf("--------------\n");
	// printf("Size: %d\n", printf("%d %c ", -d, c));
	// printf("Size: %d\n", ft_printf("%d %c ", -d, c));
	// printf("--------------\n");
	// printf("Size: %d\n", printf("%.i ", 2));
	// printf("Size: %d\n", ft_printf("%.i ", 2));
	// printf("--------------\n");
	// printf("Size: %d\n", printf("%8.5d %5.i ", 35, 0));
	// printf("Size: %d\n", ft_printf("%8.5d %5.i ", 35, 0));
	// printf("--------------\n");
	// printf("Size: %d\n", printf("%.c ", c));
	// printf("Size: %d\n", ft_printf("%.c ", c));
	// printf("--------------\n");
	// printf("Size: %d\n", printf(" %-5c ", '0'));
	// printf("Size: %d\n", ft_printf(" %-5c ", '0'));
	// printf("--------------\n");
	// printf("Size: %d\n", printf(" %-3c", '0' - 256));
	// printf("Size: %d\n", ft_printf(" %-3c", '0' - 256));
	// printf("--------------\n");
	// printf("Size: %d\n", printf(" %-1c %-2c %-3c ", '0', 0, '1'));
	// printf("Size: %d\n", ft_printf(" %-1c %-2c %-3c ", '0', 0, '1'));
	// printf("--------------\n");
	// printf("Size: %d\n", printf(" %-1c %-2c %-3c ", ' ', ' ', ' '));
	// printf("Size: %d\n", ft_printf(" %-1c %-2c %-3c ", ' ', ' ', ' '));
	// printf("--------------\n");
	// printf("Size: %d\n", printf(" %-3d ", -11));
	// printf("Size: %d\n", ft_printf(" %-3d ", -11));
	// printf("--------------\n");
	// printf(" Size: %d\n", printf("%08d", 0));
	// printf(" Size: %d\n", ft_printf("%08d", 0));
	// printf("--------------\n");
	// printf(" Size: %d\n", printf("%08.8d", 3));
	// printf(" Size: %d\n", ft_printf("%08.8d", 3));
	// printf("--------------\n");
	// printf(" Size: %d\n", printf("%08.3d", 0));
	// printf(" Size: %d\n", ft_printf("%08.3d", 0));
	// printf("--------------\n");
	// printf(" Size: %d\n", printf("%08.3d", 3));
	// printf(" Size: %d\n", ft_printf("%08.3d", 3));
	// printf("--------------\n");
	// printf(" Size: %d\n", printf("%03.8d", 0));
	// printf(" Size: %d\n", ft_printf("%03.8d", 0));
	// printf("--------------\n");
	// printf(" Size: %d\n", printf("%0.8d", 0));
	// printf(" Size: %d\n", ft_printf("%0.8d", 0));
	// printf("--------------\n");
	printf(" Size: %d\n", printf("%015u %03u", ULONG_MAX - 1, ULONG_MAX));
	printf(" Size: %d\n", ft_printf("%015u %03u", ULONG_MAX - 1, ULONG_MAX));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%-5.0d", 0));
	printf(" Size: %d\n", ft_printf("%-5.0d", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%5.0d", 0));
	printf(" Size: %d\n", ft_printf("%5.0d", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%-8.5u", 0));
	printf(" Size: %d\n", ft_printf("%-8.5u", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%08.3u", 8323333));
	printf(" Size: %d\n", ft_printf("%08.3u", 8323333));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%d", 0));
	printf(" Size: %d\n", ft_printf("%d", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%3i", 0));
	printf(" Size: %d\n", ft_printf("%3i", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%.7i", -54));
	printf(" Size: %d\n", ft_printf("%.7i", -54));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%04i", -532));
	printf(" Size: %d\n", ft_printf("%04i", -532));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%-8.13i", 833375));
	printf(" Size: %d\n", ft_printf("%-8.13i", 833375));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%d", 0));
	printf(" Size: %d\n", ft_printf("%d", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%.3d", 0));
	printf(" Size: %d\n", ft_printf("%.3d", 0));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%07d", -54));
	printf(" Size: %d\n", ft_printf("%07d", -54));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%-12.20d", -54));
	printf(" Size: %d\n", ft_printf("%-12.20d", -54));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%-4.18u", 54));
	printf(" Size: %d\n", ft_printf("%-4.18u", 54));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%.8u", LONG_MAX));
	printf(" Size: %d\n", ft_printf("%.8u", LONG_MAX));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%.8u", LONG_MIN));
	printf(" Size: %d\n", ft_printf("%.8u", LONG_MIN));
	printf("--------------\n");
	printf(" Size: %d\n", printf("%.8u", ULONG_MAX));
	printf(" Size: %d\n", ft_printf("%.8u", ULONG_MAX));
	printf("--------------\n");
	printf("--------------\n");
	printf("--------------\n");
	s[1] = d;
	c = d;
}
