/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:51:54 by mikabuto          #+#    #+#             */
/*   Updated: 2022/01/04 14:51:54 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> //TODO
# include <limits.h> //TODO

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
	int		perc;
	int		sp;
	int		hash;
	int		plus;
	int		is_zero;
}	t_print;

int			ft_printf(const char *format, ...);
void		init_tab(t_print *tab);
int			cspdiux(char c);
int			increase_pos(int *a);
int			eval_prc_wdt(int *a, int *b, const char *format, int pos);
int			ft_strlen(char *str);
void		ft_fill(t_print *tab, int len, char c);
int			ft_print_char(t_print *tab);
int			ft_print_str(t_print *tab);
int			ft_min(int a, int b);
void		clear_tab(t_print *tab);
int			ft_putneghex(t_print *tab, int shift);
void		ft_swap(char *a, char *b);
int			ft_num_len(long long int n);
int			ft_power(int a);
int			ft_putnbr(t_print *tab);
void		ft_putchar(char c, t_print *tab);
int			ft_putstr(char *str, t_print *tab);
void		ft_check_flags(t_print *tab, int len, int sign, int after);
int			ft_putunsnbr(t_print *tab);
int			ft_print_perc(t_print *tab);
int			ft_putptr(t_print *tab);
void		case_nullstr(char *s, t_print *tab);
long int	case_negnum(long int n, int *sign, t_print *tab);
int			ft_max(int a, int b);

#endif