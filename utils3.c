/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:32:23 by mikabuto          #+#    #+#             */
/*   Updated: 2022/01/04 14:32:23 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(long long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_power(int a)
{
	int	n;

	n = 1;
	while (a--)
		n *= 10;
	return (n);
}

void	ft_check_flags(t_print *tab, int len, int sign, int after)
{
	if (!after)
	{
		if (tab->prc)
			ft_fill(tab, tab->prc - ft_min(len, tab->prc), '0');
		if (tab->wdt && !(tab->dash) && tab->zero)
		{
			if (tab->is_zero && tab->pnt && !(tab->prc))
				ft_fill(tab, tab->wdt - ft_min(len + sign, tab->wdt), ' ');
			else
				ft_fill(tab, tab->wdt - ft_min(len + sign, tab->wdt), '0');
		}
		if (tab->plus && !sign)
			ft_fill(tab, 1, '+');
		//printf("meow\n");
	}
	else
	{
		if (tab->wdt && tab->dash && !(tab->pnt))
			ft_fill(tab, tab->wdt - ft_min(len + sign, tab->wdt), ' ');
		else if (tab->wdt && tab->dash && tab->pnt)
			ft_fill(tab, tab->wdt - ft_max(tab->prc + sign, len + sign), ' ');
	}
}

void	ft_fill(t_print *tab, int len, char c)
{
	int	i;

	i = -1;
	while (++i < len)
		tab->tl += write(1, &c, 1);
}

void	case_nullstr(char *s, t_print *tab)
{
	if (!s)
	{
		if (tab->prc)
			tab->tl += write(1, "(null)", ft_min(tab->prc, 6));
		else if (tab->wdt)
			tab->tl += write(1, "(null)", 6);
	}
}
