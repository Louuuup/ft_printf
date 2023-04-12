/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:37:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/04/12 12:49:31 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		data->pre = nb;
	if (nb == 0 && data->pre == 0)
		nb_len = 0;
	if (data->pre_itself && data->flag[2] == '0')
		data->flag[2] = '\0';
	if (int_disp0(nb, data))
		return (ERROR);
	if (int_disp1(neg, nb_len, data))
		return (ERROR);
	return (d_dispatcher1(nb, nb_len, neg, data));
}

int	d_dispatcher1(int nb, int nb_len, int neg, t_data *data)
{
	if (nb < 0 && nb != -2147483648)
	{
		if (ft_putchar('-', data->len))
			return (ERROR);
		nb = -nb;
	}
	if (int_disp2(neg, nb_len, data))
		return (ERROR);
	if (!(nb == 0 && (data->pre == 0)))
	{
		if (ft_putnbr(nb, data->len))
			return (ERROR);
	}
	else if (data->wdh && nb)
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
	if (data->pre_itself && nb == 0)
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
