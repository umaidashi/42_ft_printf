/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:52:04 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/21 01:36:44 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	i = 0;
	if (!dst && !src)
		return (0);
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (dp < sp)
	{
		while (i < len)
		{
			dp[i] = sp[i];
			i++;
		}
		return (dp);
	}
	while (len > 0)
	{
		dp[len - 1] = sp[len - 1];
		len--;
	}
	return (dp);
}
