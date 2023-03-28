/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:26:06 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/03/28 16:02:40 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// POSSIBLE TO STACK IF STATEMENTS IF NEEDED (||)
// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	c_dispatcher(int nb, t_data *data)
{
	if (data->pre_itself)
		data->pre = nb;
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(1, data))
		return (ERROR);
	if (int_disp2(nb, data))
		return (ERROR);
	if (ft_putchar(nb, data->len))
		return (ERROR);
	if (int_disp3(nb, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	d_dispatcher(int nb, t_data *data)
{
	if (data->pre_itself && nb < 1)
		data->pre = nb;
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(int_len(nb), data))
		return (ERROR);
	if (nb < 0)
	{
		if (ft_putchar('-', data->len))
			return (ERROR);
		nb = -nb;
	}
	if (int_disp2(nb, data))
		return (ERROR);
	if (ft_putnbr(nb, data->len))
		return (ERROR);
	if (int_disp3(nb, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	u_dispatcher(unsigned int nb, t_data *data)
{
	if (data->pre_itself)
		data->pre = nb;
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(int_len(nb), data))
		return (ERROR);
	if (int_disp2(nb, data))
		return (ERROR);
	if (ft_putnbr_unsigned(nb, data->len))
		return (ERROR);
	if (int_disp3(nb, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts
// Some are executed before or after "putchar", depending on context.
int	p_dispatcher(unsigned long nb, t_data *data)
{
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(int_len(nb), data))
		return (ERROR);
	if (int_disp2(nb, data))
		return (ERROR);
	if (ft_putnbr(nb, data->len))
		return (ERROR);
	if (int_disp3(nb, data))
		return (ERROR);
	return (NO_ERROR);
}

// Dispatches flags and argmuemnts  * [iflc = 0 means x. Else X]
// Some are executed before or after "putchar", depending on context.
int	x_dispatcher(unsigned int nb, t_data *data, int is_lwc)
{
	if (data->pre_itself)
		data->pre = nb;
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(int_len(nb), data))
		return (ERROR);
	if (int_disp2(nb, data))
		return (ERROR);
	if (is_lwc)
	{
		if (ft_puthex1(nb, data->len))
			return (ERROR);
		else if (ft_puthex(nb, data->len))
			return (ERROR);
	}
	if (int_disp3(nb, data))
		return (ERROR);
	return (NO_ERROR);
}

int	s_dispatcher(char *s, t_data *data)
{
	if (!s)
		return (ft_putstr("(null)", -1, data->len));
	if (data->flag[1] == '0')
		ft_flood(data->wdh - ft_strlen(s), data->flag[1], data->len);
	else if (data->flag[1] != '-')
		ft_flood(data->wdh - ft_strlen(s), ' ', data->len);
	ft_putstr(s, data->pre, data->len);
	if (data->flag[1] == '-')
		ft_flood(data->wdh - ft_strlen(s), ' ', data->len);
	return (0);
}
