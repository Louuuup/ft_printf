/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:22:49 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/17 21:06:51 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//Flags: '#-+ 0'  Flags[0]; '+ ' Flags[1]: '-0' Flags[3]: '#'
//Width: Any number above 0. To have 0, need to use '\0' I think? "-1" to skip
//Precision: "".<x>"" <x> is replaced by any (unsgiend?) number. "-1" to skip
//Type: 'csdiupxX'
typedef struct formats
{
	char	flag[3];
	int		width;
	int		precision;
	char	type;
}t_format;

int		ft_putchar(char c, size_t *len);
int		ft_putstr(char *str, size_t *len);
int		ft_putnbr(int n, size_t *len);
int		ft_puthexa(int n, size_t *len);
int		ft_putptr(char *s, size_t *len);
int		ft_putnbr_unsigned(unsigned	int n, size_t *len);
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);

#endif
