/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:01:25 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/28 01:27:04 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	char	*str;
	t_args	args;
	va_list	ap;

	va_start(ap, s);
	str = (char *)s;
	if (!str)
		return (0);
	res = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_parse_args(str, &args, &ap);
			res += ft_put_conv(&args, &ap);
			continue ;
		}
		res += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (res);
}
