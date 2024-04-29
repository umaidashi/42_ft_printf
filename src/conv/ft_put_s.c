/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:07:59 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 18:34:46 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_s_help(int *width, int *is_minus, int *putlen, char *str);

int	ft_put_s(t_args *args, va_list *ap)
{
	char	*str;
	int		putlen;
	int		margin;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	if (!(args->has_prec) && !(args->has_width))
		return (ft_putstr(str));
	if (!args->has_width && args->zero_prec)
		return (0);
	putlen = (int)ft_strlen(str);
	if (args->has_prec && putlen > args->prec)
		putlen = args->prec;
	margin = 0;
	if (args->has_width)
		margin = args->width - putlen;
	return (ft_put_s_help(&margin, &(args->f_minus), &putlen, str));
}

static int	ft_put_s_help(int *margin, int *is_minus, int *putlen, char *str)
{
	int	res;

	res = 0;
	if (!(*is_minus))
		res += ft_putcharl(' ', *margin);
	res += ft_putstrl(str, *putlen);
	if ((*is_minus))
		res += ft_putcharl(' ', *margin);
	return (res);
}
