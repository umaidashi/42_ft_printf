/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:43:09 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 18:34:07 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_putlen(unsigned int u, t_args *args);
static int	ft_get_margin(unsigned int u, t_args *args, int putlen);
static int	ft_put_padding(unsigned int u, t_args *args, int margin);

int	ft_put_u(t_args *args, va_list *ap)
{
	unsigned int	u;
	int				putlen;
	int				margin;
	int				padding;
	int				res;

	res = 0;
	u = va_arg(*ap, unsigned int);
	putlen = ft_get_putlen(u, args);
	margin = ft_get_margin(u, args, putlen);
	padding = putlen - ft_get_digits_u(u);
	if (!args->f_minus && (!args->f_zero || (args->f_zero && args->prec)))
		res += ft_putcharl(' ', margin);
	if (args->f_zero && margin && padding == 0)
		res += ft_put_padding(u, args, margin);
	res += ft_putcharl('0', padding);
	if (!(u == 0 && args->zero_prec))
		res += ft_putnbr_u(u);
	if (args->f_minus && !(args->f_zero && args->zero_prec))
		res += ft_putcharl(' ', margin);
	return (res);
}

static int	ft_get_putlen(unsigned int u, t_args *args)
{
	int	len;

	len = ft_get_digits_u(u);
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
	if (args->has_width && args->width > putlen)
		margin = (args->width - putlen);
	return (margin);
}

static int	ft_put_padding(unsigned int u, t_args *args, int margin)
{
	if (args->zero_prec)
		return (ft_putcharl(' ', margin));
	else if (!(args->has_prec && args->prec <= ft_get_digits_u(u)))
		return (ft_putcharl('0', margin));
	return (0);
}
