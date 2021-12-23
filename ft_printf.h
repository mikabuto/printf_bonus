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
void	ft_fill_sp(t_print *tab, int len);
int		ft_print_char(t_print *tab, int pos);
int		ft_print_str(t_print *tab, int pos);
int		ft_min(int a, int b);

# endif