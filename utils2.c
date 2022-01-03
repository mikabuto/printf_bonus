#include "ft_printf.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	clear_tab(t_print *tab)
{
	tab->wdt = 0;		//width field
	tab->prc = 0;		//precision
	tab->zero = 0;		// flag '0'
	tab->pnt = 0;		// .
	tab->dash = 0;		// -
	tab->sign = 0;		//pos or neg numer
	tab->is_zero = 0;	//is number zero?
	tab->perc = 0;		// %
	tab->sp = 0;		// ' '
	tab->hash = 0;		// #
	tab->plus = 0;		// +
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_putchar(char c, t_print *tab)
{
	tab->tl += write(1, &c, 1);
}

int		ft_putstr(char *str, t_print *tab)
{
	while (*str)
	{
		tab->tl += write(1, &str, 1);
		str++;
	}
	return (1);
}