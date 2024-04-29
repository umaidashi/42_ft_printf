/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:35:53 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/28 01:26:39 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_conv(t_args *args, va_list *ap)
{
	if (args->conv == '%')
		return (ft_put_percent(args));
	if (args->conv == 'c')
		return (ft_put_c(args, ap));
	if (args->conv == 's')
		return (ft_put_s(args, ap));
	if (args->conv == 'p')
		return (ft_put_p(args, ap));
	if (args->conv == 'd' || args->conv == 'i')
		return (ft_put_i(args, ap));
	if (args->conv == 'u')
		return (ft_put_u(args, ap));
	if (args->conv == 'x' || args->conv == 'X')
		return (ft_put_x(args, ap));
	return (0);
}
