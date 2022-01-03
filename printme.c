#include "ft_printf.h"

void	ft_fill(t_print *tab, int len, char c)
{
	int		i;
	int		width;

	i = -1;
	if (tab->wdt)
		width = tab->wdt;
	else if (tab->prc)
		width = tab->prc;
	while (++i < width - len)
		tab->tl += write(1, &c, 1);
}

int	ft_print_char(t_print *tab)
{
	char c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !(tab->dash))
		ft_fill(tab, 1, ' ');
	tab->tl += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_fill(tab, 1, ' ');
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
	if (tab->wdt && !(tab->dash))
		ft_fill(tab, ft_min(strlen, tab->wdt), ' ');
	while (s[++i])
	{
		if (tab->pnt && i >= tab->prc)
			break ;
		tab->tl += write(1, &(s[i]), 1);
	}
	if (tab->wdt && tab->dash)
		ft_fill(tab, ft_min(strlen, tab->wdt), ' ');
	clear_tab(tab);
	return (1);
}

int	ft_putnbr(t_print *tab)
{
	int		len;
	long int		n;
	int		i;

	i = -1;
	n = (long int)va_arg(tab->args, int);
	if (tab->prc)
		ft_fill(tab, ft_min(strlen, tab->prc), '0');
	if (tab->wdt && !(tab->dash) && !(tab->zero))
		ft_fill(tab, ft_min(strlen, tab->wdt), ' ');
	if (tab->wdt && !(tab->dash) && tab->zero)
		ft_fill(tab, ft_min(strlen, tab->wdt), '0');
	if (n == -2147483648)
		return (ft_putstr("-2147483648", tab));
	if (n < 0)
	{
		ft_putchar('-', tab);
		n = -n;
	}
	len = ft_num_len(n);
	while (++i < len)
		ft_putchar((n / ft_power(len - i - 1) % 10) + '0', tab);
	return (1);
}