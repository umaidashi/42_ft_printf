/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:20:27 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 17:34:07 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digits_i(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_get_digits_u(unsigned int u)
{
	int	count;

	count = 1;
	while (u >= 10)
	{
		u = u / 10;
		count++;
	}
	return (count);
}

int	ft_get_digits_llu_base(unsigned long long llu)
{
	int	count;

	count = 1;
	while (llu >= 16)
	{
		llu = llu / 16;
		count++;
	}
	return (count);
}
