/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:41:42 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/22 00:02:27 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set);
static char	*ft_return_allocate_memory(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	str;
	size_t	end;
	size_t	i;
	char	*res;

	if (!s1)
		return (0);
	cnt = ft_strlen(s1);
	str = 0;
	while (ft_is_set(s1[str], set) && str++ < ft_strlen(s1) && cnt > 0)
		cnt--;
	end = ft_strlen(s1) - 1;
	while (ft_is_set(s1[end], set) && 0 <= end-- && cnt > 0)
		cnt--;
	if (cnt == 0)
		return (ft_return_allocate_memory());
	res = (char *)ft_calloc((cnt + 1), sizeof(char));
	if (!res)
		return (0);
	i = -1;
	while (str + ++i <= end)
		res[i] = s1[str + i];
	return (res);
}

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_return_allocate_memory(void)
{
	char	*res;

	res = (char *)ft_calloc(1, sizeof(char));
	return (res);
}

// set no moji to tigau mono ga kuru made,
// saisyokara to saigokara moji wo susumeru.
// sonoaida mojisuu wo kazoe, malloc site, onaji jouken de loop si, cpy suru
