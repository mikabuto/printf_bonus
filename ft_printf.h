#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h> //TODO
#include <limits.h> //TODO

typedef struct s_print                       
{                        
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
	int		hash;
	int		plus;
}	t_print;

int 	ft_printf(const char *format, ...);
void	init_tab(t_print *tab);
int		cspdiuxX(char c);
int		increase_pos(int *a);
int		eval_prc_wdt(int *a, int *b, const char *format, int pos);
int		ft_strlen(char *str);
void	ft_fill(t_print *tab, int len, char c);
int		ft_print_char(t_print *tab);
int		ft_print_str(t_print *tab);
int		ft_min(int a, int b);
void	clear_tab(t_print *tab);
int		ft_putneghex(t_print *tab, int shift);
void	ft_swap(char *a, char *b);
int		ft_num_len(long long int n);
int		ft_power(int a);
int		ft_putnbr(t_print *tab);
void	ft_putchar(char c, t_print *tab);
int		ft_putstr(char *str, t_print *tab);

# endif