/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:37:46 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/21 00:56:41 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	i = 0;
	if (!dst && !src)
		return (0);
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dp);
}
