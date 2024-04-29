/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:01:17 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/17 22:51:37 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((char)c == s[i])
		{
			p = (char *)&(s[i]);
			return (p);
		}
		i--;
	}
	if ((char)c != 0)
		return (0);
	p = (char *)&(s[i]);
	return (p);
}
