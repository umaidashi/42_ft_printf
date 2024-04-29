/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:30:32 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/21 11:00:30 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return ;
	i = 0;
	len = (unsigned int)ft_strlen(s);
	while (i < len)
	{
		f(i, &(s[i]));
		i++;
	}
}

// tester ha hitotume awanaito zenbu awanai
// mojiretu zentai no address janaku, sono moji no address ga hosiinkai!!!! oko
