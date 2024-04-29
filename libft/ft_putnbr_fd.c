/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:01:18 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/21 11:34:46 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		str[12];
	long int	ln;
	int			length;

	length = 0;
	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	while (ln >= 10)
	{
		str[length++] = ln % 10 + '0';
		ln = ln / 10;
	}
	str[length] = ln + '0';
	while (length >= 0)
		write(fd, &(str[length--]), 1);
}
