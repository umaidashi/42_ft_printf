/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:11:52 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 18:36:29 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_putlen(unsigned int u, t_args *args);
static int	ft_get_margin(unsigned int u, t_args *args, int putlen);
static int	ft_put_prefix(t_args *args, unsigned int u, int padding);
static int	ft_put_x_help(unsigned int *u, t_args *args);

int	ft_put_x(t_args *args, va_list *ap)
{
	int				res;
	unsigned int	u;
	int				putlen;
	int				margin;
	int				padding;

	res = 0;
	u = va_arg(*ap, unsigned long);
	putlen = ft_get_putlen(u, args);
	margin = ft_get_margin(u, args, putlen);
	padding = putlen - ft_get_digits_llu_base(u);
	if (!args->f_minus && (!args->f_zero || (args->f_zero && args->prec)))
		res += ft_putcharl(' ', margin);
	if (args->f_zero && margin && padding == 0)
	{
		if (args->zero_prec)
			res += ft_putcharl(' ', margin);
		else if (!(args->has_prec && args->prec <= ft_get_digits_llu_base(u)))
			res += ft_putcharl('0', margin);
	}
	res += ft_put_prefix(args, u, padding);
	res += ft_put_x_help(&u, args);
	if (args->f_minus && !(args->f_zero && args->zero_prec))
		res += ft_putcharl(' ', margin);
	return (res);
}

static int	ft_get_putlen(unsigned int u, t_args *args)
{
	int	len;

	len = ft_get_digits_llu_base(u);
	if (args->has_prec && args->prec > len)
		len = args->prec;
	return (len);
}

static int	ft_get_margin(unsigned int u, t_args *args, int putlen)
{
	int	margin;

	margin = 0;
	if (u == 0 && args->zero_prec)
		putlen--;
	if (args->f_sharp && u != 0)
		putlen += 2;
	if (args->has_width && args->width > putlen)
		margin = (args->width - putlen);
	return (margin);
}

static int	ft_put_prefix(t_args *args, unsigned int u, int padding)
{
	int	res;

	res = 0;
	if (args->f_sharp && u != 0)
	{
		if (args->conv == 'X')
			res += ft_putstr("0X");
		else
			res += ft_putstr("0x");
	}
	res += ft_putcharl('0', padding);
	return (res);
}

static int	ft_put_x_help(unsigned int *u, t_args *args)
{
	int		i;
	int		res;
	char	tmp[16];

	if (*u == 0 && args->zero_prec)
		return (0);
	res = 0;
	i = 0;
	if (*u == 0)
		return (ft_putchar('0'));
	while (*u >= 16)
	{
		tmp[i++] = BASE[(int)(*u % 16)];
		*u = *u / 16;
	}
	tmp[i] = BASE[*u];
	while (i >= 0)
	{
		if (args->conv == 'X' && ft_isalpha(tmp[i]))
			res += (ft_putchar(ft_toupper(tmp[i])));
		else
			res += (ft_putchar(tmp[i]));
		i--;
	}
	return (res);
}
