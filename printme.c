/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:30:30 by mikabuto          #+#    #+#             */
/*   Updated: 2022/01/04 14:30:30 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_perc(t_print *tab)
{
	if (tab->wdt && !(tab->dash) && tab->sp)
		ft_fill(tab, tab->wdt - 1, ' ');
	if (tab->wdt && !(tab->dash) && tab->zero)
		ft_fill(tab, tab->wdt - 1, '0');
	tab->tl += write(1, "%", 1);
	if (tab->wdt && tab->dash)
		ft_fill(tab, tab->wdt - 1, ' ');
	clear_tab(tab);
	return (1);
}

int	ft_print_str(t_print *tab)
{
	char	*s;
	int		strlen;
	int		i;

	s = va_arg(tab->args, char *);
	strlen = ft_strlen(s);
	i = -1;
	if (!s)
		strlen = 6;
	if (tab->wdt && !(tab->dash))
		ft_fill(tab, tab->wdt - ft_min(strlen, tab->wdt), ' ');
	case_nullstr(s, tab);
	while (s && s[++i])
	{
		if (tab->pnt && i >= tab->prc)
			break ;
		tab->tl += write(1, &(s[i]), 1);
	}
	if (tab->wdt && tab->dash)
		ft_fill(tab, tab->wdt - ft_min(strlen, tab->wdt), ' ');
	clear_tab(tab);
	return (1);
}

int	ft_putnbr(t_print *tab)
{
	int			len;
	long int	n;
	int			i;
	int			sign;

	i = -1;
	n = (long int)va_arg(tab->args, int);
	if (!n)
		tab->is_zero = 1;
	sign = 0;
	if (tab->sp && n >= 0)
		ft_fill(tab, 1, ' ');
	if (tab->wdt && !(tab->dash) && !(tab->zero))
		ft_fill(tab, tab->wdt - ft_min(ft_num_len(n), tab->wdt), ' ');
	if (!n && tab->pnt && !(tab->prc) && tab->wdt)
		ft_fill(tab, 1, ' ');
	n = case_negnum(n, &sign, tab);
	len = ft_num_len(n);
	ft_check_flags(tab, len, sign, 0);
	while (++i < len)
	{
		if (!n && tab->pnt && i >= tab->prc)
			break ;
		ft_putchar((n / ft_power(len - i - 1) % 10) + '0', tab);
	}
	ft_check_flags(tab, len, sign, 1);
	clear_tab(tab);
	return (1);
}

int	ft_putunsnbr(t_print *tab)
{
	int				len;
	int				i;
	long long int	n;

	n = va_arg(tab->args, unsigned int);
	if (n < 0)
		n = 4294967296 + n;
		if (tab->sp && n >= 0)
		ft_fill(tab, 1, ' ');
	len = ft_num_len(n);
	i = -1;
	if (tab->wdt && !(tab->dash) && !(tab->zero))
		ft_fill(tab, tab->wdt - ft_min(len, tab->wdt), ' ');
	ft_check_flags(tab, len, 0, 0);
	while (++i < len)
		ft_putchar((n / ft_power(len - i - 1) % 10) + '0', tab);
	ft_check_flags(tab, len, 0, 1);
	clear_tab(tab);
	return (1);
}

int	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !(tab->dash))
		ft_fill(tab, tab->wdt - 1, ' ');
	tab->tl += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_fill(tab, tab->wdt - 1, ' ');
	clear_tab(tab);
	return (1);
}
