/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:37:59 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/17 22:51:00 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	while (*s)
	{
		if ((char)c == *s)
		{
			p = (char *)s;
			return (p);
		}
		s++;
	}
	if (c != 0)
		return (0);
	p = (char *)s;
	return (p);
}
