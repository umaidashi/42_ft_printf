/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:56:09 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/23 21:10:50 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s && !start)
		return (0);
	size = len;
	if (ft_strlen(s) < size)
		size = ft_strlen(s);
	if (ft_strlen(s) < start)
	{
		str = (char *)ft_calloc(1, sizeof(char));
		return (str);
	}
	str = (char *)ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
