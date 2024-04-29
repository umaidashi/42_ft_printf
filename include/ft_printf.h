/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:58:15 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 18:28:23 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FLAGS "-+#0 "
# define CONV "cspdiuxX%"
# define BASE "0123456789abcdef"

typedef struct s_args
{
	int	conv;
	int	has_width;
	int	width;
	int	has_prec;
	int	prec;
	int	zero_prec;
	int	f_minus;
	int	f_plus;
	int	f_zero;
	int	f_space;
	int	f_sharp;
}		t_args;

int		ft_printf(const char *s, ...);
char	*ft_parse_args(char *str, t_args *args, va_list *ap);
int		ft_put_conv(t_args *args, va_list *ap);
int		ft_put_percent(t_args *args);
int		ft_put_c(t_args *args, va_list *ap);
int		ft_put_s(t_args *args, va_list *ap);
int		ft_put_p(t_args *args, va_list *ap);
int		ft_put_i(t_args *args, va_list *ap);
int		ft_put_u(t_args *args, va_list *ap);
int		ft_put_x(t_args *args, va_list *ap);
int		ft_get_digits_i(int n);
int		ft_get_digits_u(unsigned int u);
int		ft_get_digits_llu_base(unsigned long long llu);
int		ft_putstr(char *str);
int		ft_putstrl(char *str, int l);
int		ft_putcharl(char c, int l);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int u);

#endif
