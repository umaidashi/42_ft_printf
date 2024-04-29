/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:12:25 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 17:10:52 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_percent(t_args *args)
{
	int	res;

	res = 0;
	if (!args->f_minus)
	{
		if (args->f_zero)
			res += ft_putcharl('0', args->width - 1);
		else
			res += ft_putcharl(' ', args->width - 1);
	}
	res += (ft_putchar('%'));
	if (args->f_minus)
		res += ft_putcharl(' ', args->width - 1);
	return (res);
}
