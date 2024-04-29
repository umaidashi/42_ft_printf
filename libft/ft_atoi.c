/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:41:00 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/21 17:30:30 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						f;
	unsigned long long int	n;

	f = 1;
	n = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			f *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * f);
}

// static unsigned long long int	ft_overflow(unsigned long long int n, int f,
// 									int flg);
// static int						ft_irregular(const char *str);

// int	ft_atoi(const char *str)
// {
// 	int						f;
// 	unsigned long long int	n;

// 	f = 1;
// 	n = 0;
// 	if (ft_irregular(str))
// 		return (-1);
// 	while ((9 <= *str && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == 43 || *str == 45)
// 	{
// 		if (*str == 45)
// 			f *= -1;
// 		str++;
// 	}
// 	while (ft_isdigit(*str))
// 	{
// 		n *= 10;
// 		n += *str - '0';
// 		n -= ft_overflow(n, f, 0);
// 		str++;
// 	}
// 	n += ft_overflow(n, f, 1);
// 	return (n * f);
// }

// static unsigned long long int	ft_overflow(unsigned long long int n, int f,
// 		int flg)
// {
// 	if (LONG_MAX < n && f < 0)
// 		return (LONG_MIN + (n - LONG_MIN));
// 	if (LONG_MAX < n)
// 	{
// 		if (n - LONG_MAX > 0 && n - LONG_MAX < LONG_MAX)
// 		{
// 			if (flg)
// 				return (LONG_MAX);
// 			else
// 				return (n - LONG_MAX);
// 		}
// 		return (LONG_MAX);
// 	}
// 	return (0);
// }

// static int	ft_irregular(const char *str)
// {
// 	if (ft_strncmp(str, "18446744073709551616", 20))
// 		return (0);
// 	return (1);
// }
