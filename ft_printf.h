/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:22:49 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/22 17:37:11 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
}			t_format;

int			ft_putchar(char c, int *len);
int			ft_putstr(char *str, int max, int *len);
int			ft_putnbr(int n, int *len);
int			ft_puthexa(unsigned long n, int *len);
int			ft_puthexa_alt(unsigned int n, int *len);
int			ft_putptr(unsigned long s, int *len);
int			ft_putnbr_unsigned(unsigned int n, int *len);
int			ft_atoi(const char *str);
int			ft_printf(const char *str, ...);
int			c_dispatcher(va_list args, t_format *format, int *len);
void		ft_strct_clean(t_format *format);
int			int_len(int n);
int			ft_atoi(const char *str);
int			ft_flood(int size, int nb, char c, int *len);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			c_dispatcher(va_list args, t_format *format, int *len);
int			d_dispatcher(va_list args, t_format *format, int *len);
int			s_dispatcher(va_list args, t_format *format, int *len);
int			p_dispatcher(va_list args, t_format *format, int *len);

#endif
