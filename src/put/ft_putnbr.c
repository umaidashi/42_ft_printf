/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:38:40 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 17:51:48 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	str[12];
	int		length;
	int		res;

	res = 0;
	length = 0;
	if (n == -2147483648)
		return (ft_putstr("2147483648"));
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		str[length++] = n % 10 + '0';
		n = n / 10;
	}
	str[length] = n + '0';
	while (length >= 0)
		res += ft_putchar(str[length--]);
	return (res);
}

int	ft_putnbr_u(unsigned int u)
{
	char	str[12];
	int		length;
	int		res;

	res = 0;
	length = 0;
	while (u >= 10)
	{
		str[length++] = u % 10 + '0';
		u = u / 10;
	}
	str[length] = u + '0';
	while (length >= 0)
		res += ft_putchar(str[length--]);
	return (res);
}
