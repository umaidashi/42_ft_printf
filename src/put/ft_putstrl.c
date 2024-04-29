/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:21:35 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/28 16:36:11 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrl(char *str, int l)
{
	int	res;

	res = 0;
	while (*str && res < l)
	{
		res += ft_putchar(*str);
		str++;
	}
	return (res);
}
