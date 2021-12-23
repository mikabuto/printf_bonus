#include "ft_printf.h"

void	ft_fill_sp(t_print *tab, int len)
{
	char	c;
	int		i;

	c = ' ';
	i = -1;
	while (++i < tab->wdt - len)
		tab->tl += write(1, &c, 1);
}

int	ft_print_char(t_print *tab, int pos)
{
	char c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !(tab->dash))
		ft_fill_sp(tab, 1);
	tab->tl += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_fill_sp(tab, 1);
	return (pos + 1);
}

int	ft_print_str(t_print *tab, int pos)
{
	char	*s;
	int		strlen;
	int		i;

	s = va_arg(tab->args, char *);
	strlen = ft_strlen(s);
	i = -1;
	if (tab->wdt && !(tab->dash))
		ft_fill_sp(tab, ft_min(strlen, tab->prc));
	while (s[++i] && i < tab->prc)
		tab->tl += write(1, &(s[i]), 1);
	if (tab->wdt && tab->dash)
		ft_fill_sp(tab, ft_min(strlen, tab->prc));
	return (pos + 1);
}