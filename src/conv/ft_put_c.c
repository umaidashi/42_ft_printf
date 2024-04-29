/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:05 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 17:06:45 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(t_args *args, va_list *ap)
{
	int	res;
	int	width;

	res = 0;
	width = args->width - 1;
	if (!args->f_minus)
		res += ft_putcharl(' ', width);
	res += (ft_putchar((char)va_arg(*ap, int)));
	if (args->f_minus)
		res += ft_putcharl(' ', width);
	return (res);
}
