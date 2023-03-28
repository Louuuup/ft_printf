/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:22:49 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/27 21:48:32 by ycyr-roy         ###   ########.fr       */
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
//FIELD_EXCEPT: 0 = none | 1 = wdh | 2 = pre | 3 = both
typedef struct datas
{
	char	flag[3];
	int		wdh;
	int		pre;
	char	type;
	int		field_except;
	int		*len;
}			t_data;

# define ERROR -1
# define NO_ERROR 0

int			ft_putchar(char c, int *len);
int			ft_putstr(char *str, int max, int *len);
int			ft_putnbr(int n, int *len);
int			ft_puthex(unsigned long n, int *len);
int			ft_puthex1(unsigned long n, int *len);
int			ft_putptr(unsigned long s, int *len);
int			ft_putnbr_unsigned(unsigned int n, int *len);
int			ft_atoi(const char *str);
int			ft_printf(const char *str, ...);
void		ft_strct_clean(t_data *data);
int			int_len(int n);
int			ft_atoi(const char *str);
int			ft_flood(int size, char c, int *len);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			int_disp0(long long nb, t_data *data, int *len);
int			int_disp1(int nb_len, t_data *fmt, int *len);
int			int_disp2(long long nb, t_data *data, int *len);
int			int_disp3(long long nb, t_data *data, int *len);
int			c_dispatcher(int nb, t_data *fmt);
int			d_dispatcher(int nb, t_data *fmt);
int			u_dispatcher(unsigned int nb, t_data *fmt);
int			x_dispatcher(unsigned int nb, t_data *fmt, int iflc);
int			p_dispatcher(unsigned long nb, t_data *fmt);
int			s_dispatcher(char *s, t_data *data);
int			flags_handler(char *str, t_data *data, size_t i);
int			width_handler(va_list args, char *str, t_data *data, size_t i);
int			prec_handler(va_list args, char *str, t_data *data, size_t i);
int			types_handler(va_list args, char *str, t_data *data);

#endif
