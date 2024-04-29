/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:25:37 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/21 12:37:47 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_negative(int n);

char	*ft_itoa(int n)
{
	char		tmp[11];
	char		*ans;
	long int	ln;
	int			cnt;
	int			i;

	ln = n;
	if (ln < 0)
		ln *= -1;
	cnt = 0;
	while (ln >= 10)
	{
		tmp[cnt++] = '0' + ln % 10;
		ln /= 10;
	}
	tmp[cnt] = '0' + ln;
	ans = (char *)ft_calloc(cnt + ft_is_negative(n) + 2, sizeof(char));
	if (!ans)
		return (0);
	i = 0;
	if (ft_is_negative(n))
		ans[i++] = '-';
	while (0 <= cnt)
		ans[i++] = tmp[cnt--];
	return (ans);
}

static int	ft_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}
