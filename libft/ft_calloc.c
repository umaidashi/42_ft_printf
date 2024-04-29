/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:27:05 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/23 21:37:44 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*v;
	long int	total;

	total = (long int)count * (long int)size;
	if (count * size < size && count * size < count)
		return (0);
	if (total < 0)
		return (0);
	v = (void *)malloc(total);
	if (!v)
		return (0);
	ft_bzero(v, count * size);
	return (v);
}
