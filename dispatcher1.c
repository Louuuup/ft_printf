/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:26:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/04/06 09:44:51 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// POSSIBLE TO STACK IF STATEMENTS IF NEEDED (||)
// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	c_dispatcher(int nb, t_data *data)
{
	if (data->flag[1] && data->flag[2])
		data->flag[2] = '\0';
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(0, 1, data))
		return (ERROR);
	if (int_disp2(0, 1, data))
		return (ERROR);
	if (ft_putchar(nb, data->len))
		return (ERROR);
	if (int_disp3(0, 1, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
// True_nb is nb without negative int filtering.
int	d_dispatcher(int nb, t_data *data)
{
	int	nb_len;
	int	neg;

	nb_len = int_len(nb);
	if (data->flag[1] && data->flag[2])
		data->flag[2] = '\0';
	if (nb < 0)
		neg = 1;
	else
		neg = 0;
	if (data->pre_itself && nb == 0)
	{
		data->pre = nb;
		nb_len = 0;
	}
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(neg, nb_len, data))
		return (ERROR);
	if (nb < 0 && nb != -2147483648)
	{
		if (ft_putchar('-', data->len))
			return (ERROR);
		nb = -nb;
	}
	if (int_disp2(neg, nb_len, data))
		return (ERROR);
	return (d_dispatcher1(nb, nb_len, neg, data));
}

int	d_dispatcher1(int nb, int nb_len, int neg, t_data *data)
{
	if (!(nb == 0 && (data->pre == 0)))
	{
		if (ft_putnbr(nb, data->len))
			return (ERROR);
	}
	else if (data->wdh)
		if (ft_putchar(' ', data->len))
			return (ERROR);
	if (int_disp3(neg, nb_len, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	u_dispatcher(unsigned int nb, t_data *data)
{
	int	nb_len;

	nb_len = int_len(nb);
	if (data->pre_itself)
		data->pre = nb;
	if (nb == 0 && data->pre == 0)
		nb_len = 0;
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(0, nb_len, data))
		return (ERROR);
	if (int_disp2(0, nb_len, data))
		return (ERROR);
	if (!(nb == 0 && data->pre == 0))
	{
		if (ft_putnbr_unsigned(nb, data->len))
			return (ERROR);
	}
	if (int_disp3(0, nb_len, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	p_dispatcher(unsigned long nb, t_data *data)
{
	data->flag[3] = '#';
	if (put_prefix(1, 0, data))
		return (ERROR);
	if (ft_puthex(nb, data->len))
		return (ERROR);
	if (int_disp3(0, hex_len(nb) + 2, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts  * [is_lwc = 0 means x. Else X]
// Some are executed before or after "putchar", depending on context.
int	x_dispatcher(unsigned int nb, t_data *data, int is_lwc)
{
	int	nb_len;

	if (data->pre_itself && nb == 0)
		data->pre = nb;
	if (data->flag[3] == '#')
		nb_len = 2;
	else
		nb_len = 0;
	if (data->pre > 0)
		nb_len += hex_len(nb);
	if (int_disp1(0, nb_len, data))
		return (ERROR);
	if (put_prefix(nb, is_lwc, data))
		return (ERROR);
	if (int_disp2(0, nb_len, data))
		return (ERROR);
	return (x_dispatcher1(nb, data, nb_len, is_lwc));
}

int	x_dispatcher1(unsigned int nb, t_data *data, int nb_len, int is_lwc)
{
	if (is_lwc && data->pre < 0)
	{
		if (ft_puthex1(nb, data->len))
			return (ERROR);
	}
	else if (data->pre < 0)
	{
		if (ft_puthex(nb, data->len))
			return (ERROR);
	}
	else if (data->pre != 0)
		nb_len--;
	if (int_disp3(0, nb_len, data))
		return (ERROR);
	return (NO_ERROR);
}

int	s_dispatcher(char *s, t_data *data)
{
	int	s_len;

	if (!s && data->pre_itself == 0)
		return (s_dispatcher("(null)", data));
	else if (s)
		s_len = ft_strlen(s);
	if (data->pre > 0 && data->pre < s_len)
		s_len = data->pre;
	if (data->pre_itself == 1)
		s_len = 0;
	if (data->flag[2] == '0')
		ft_flood(data->wdh - s_len, data->flag[1], data->len);
	else if (data->flag[1] != '-')
		ft_flood(data->wdh - s_len, ' ', data->len);
	if (!data->pre_itself)
		ft_putstr(s, data->pre, data->len);
	if (data->flag[1] == '-')
		ft_flood(data->wdh - s_len, ' ', data->len);
	return (0);
}
