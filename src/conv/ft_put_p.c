/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:28:45 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 18:33:09 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_p_help(int margin, char *str, int i, int *is_minus);
static int	ft_put_p_null(t_args *args, int putlen);

int	ft_put_p(t_args *args, va_list *ap)
{
	unsigned long long	llu;
	char				tmp[16];
	int					i;
	int					putlen;
	int					margin;

	margin = 0;
	llu = va_arg(*ap, unsigned long long);
	putlen = ft_get_digits_llu_base(llu) + 2;
	if (!llu)
		return (ft_put_p_null(args, putlen));
	i = 0;
	while (llu >= 16)
	{
		tmp[i++] = BASE[(int)(llu % 16)];
		llu = llu / 16;
	}
	if (args->has_width && args->width > putlen)
		margin = args->width - putlen;
	tmp[i] = BASE[(int)(llu % 16)];
	return (ft_put_p_help(margin, tmp, i, &(args->f_minus)));
}

static int	ft_put_p_null(t_args *args, int putlen)
{
	int	margin;

	margin = 0;
	if (args->zero_prec)
		putlen--;
	if (args->has_width && args->width > putlen)
		margin = args->width - putlen;
	if (args->zero_prec)
		return (ft_put_p_help(margin, 0, 0, &(args->f_minus)));
	else
		return (ft_put_p_help(margin, "0", 0, &(args->f_minus)));
}

static int	ft_put_p_help(int margin, char *str, int i, int *is_minus)
{
	int	res;

	res = 0;
	if (!*is_minus)
		res += ft_putcharl(' ', margin);
	res += ft_putstr("0x");
	while (i >= 0 && str)
		res += ft_putchar(str[i--]);
	if (*is_minus)
		res += ft_putcharl(' ', margin);
	return (res);
}
