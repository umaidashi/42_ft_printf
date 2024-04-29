/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:54:51 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/27 22:09:13 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_putlen(int n, t_args *args);
static int	ft_get_margin(int n, t_args *args, int putlen);
static int	ft_put_padding(int n, t_args *args, int margin, int padding);
static int	ft_put_sign(int n, t_args *args);

int	ft_put_i(t_args *args, va_list *ap)
{
	int	n;
	int	res;
	int	putlen;
	int	margin;
	int	padding;

	res = 0;
	n = va_arg(*ap, int);
	putlen = ft_get_putlen(n, args);
	margin = ft_get_margin(n, args, putlen);
	padding = putlen - ft_get_digits_i(n);
	if (!args->f_minus && (!args->f_zero || (args->f_zero && args->prec)
			|| (args->zero_prec)))
		res += ft_putcharl(' ', margin);
	res += ft_put_sign(n, args);
	res += ft_put_padding(n, args, margin, padding);
	if (!(n == 0 && args->zero_prec))
		res += ft_putnbr(n);
	if (args->f_minus && (!(n == 0 && args->zero_prec) || (args->zero_prec)))
		res += ft_putcharl(' ', margin);
	return (res);
}

static int	ft_get_putlen(int n, t_args *args)
{
	int	len;

	if (n == 0 && args->zero_prec)
		return (0);
	len = ft_get_digits_i(n);
	if (args->has_prec && args->prec > len)
		len = args->prec;
	return (len);
}

static int	ft_get_margin(int n, t_args *args, int putlen)
{
	int	margin;

	margin = 0;
	if (args->has_width && args->width > putlen)
	{
		margin = (args->width - putlen);
		if (!(n == 0 && args->zero_prec))
			if (n < 0 || args->f_plus || args->f_space)
				margin--;
	}
	return (margin);
}

static int	ft_put_padding(int n, t_args *args, int margin, int padding)
{
	int	res;

	res = 0;
	if (args->f_zero && margin && padding == 0 && !args->f_minus)
		if (!(args->has_prec && args->prec <= ft_get_digits_i(n)))
			res += (ft_putcharl('0', margin));
	res += ft_putcharl('0', padding);
	return (res);
}

static int	ft_put_sign(int n, t_args *args)
{
	if (n == 0 && args->zero_prec)
		return (0);
	if (n < 0)
		return (ft_putchar('-'));
	if (args->f_plus)
		return (ft_putchar('+'));
	if (args->f_space)
		return (ft_putchar(' '));
	return (0);
}
