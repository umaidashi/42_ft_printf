/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:36:33 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/29 18:30:58 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_args(t_args *args);
char	*ft_parse_flags(t_args *args, char *str);
char	*ft_parse_width(t_args *args, char *str, va_list *ap);
char	*ft_parse_prec(t_args *args, char *str, va_list *ap);

char	*ft_parse_args(char *str, t_args *args, va_list *ap)
{
	if (!str || *str != '%')
		return (str);
	str++;
	while (*str)
	{
		ft_init_args(args);
		str = ft_parse_flags(args, str);
		str = ft_parse_width(args, str, ap);
		str = ft_parse_prec(args, str, ap);
		if (ft_strchr(CONV, *str))
		{
			args->conv = *str;
			return (++str);
		}
		str++;
	}
	return (str);
}

char	*ft_parse_flags(t_args *args, char *str)
{
	if (!ft_strchr(FLAGS, *str))
		return (str);
	while (ft_strchr(FLAGS, *str))
	{
		if (*str == '-')
			args->f_minus = 1;
		if (*str == '+')
			args->f_plus = 1;
		if (*str == ' ')
			args->f_space = 1;
		if (*str == '0')
			args->f_zero = 1;
		if (*str == '#')
			args->f_sharp = 1;
		str++;
	}
	return (str);
}

char	*ft_parse_width(t_args *args, char *str, va_list *ap)
{
	int	width;

	if (ft_isdigit(*str))
	{
		args->has_width = 1;
		args->width = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		args->has_width = 1;
		width = va_arg(*ap, int);
		if (width < 0)
		{
			args->f_minus = 1;
			args->width = width * -1;
		}
		else
			args->width = width;
		str++;
	}
	return (str);
}

char	*ft_parse_prec(t_args *args, char *str, va_list *ap)
{
	int	prec;

	if (*str == '.')
	{
		str++;
		args->has_prec = 1;
		if (ft_isdigit(*str))
		{
			args->prec = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str == '*')
		{
			prec = va_arg(*ap, int);
			if (prec < 0)
				args->has_prec = 0;
			else
				args->prec = prec;
			str++;
		}
	}
	if (args->has_prec && args->prec == 0)
		args->zero_prec = 1;
	return (str);
}

void	ft_init_args(t_args *args)
{
	args->conv = 0;
	args->f_minus = 0;
	args->f_plus = 0;
	args->f_zero = 0;
	args->f_sharp = 0;
	args->f_space = 0;
	args->has_width = 0;
	args->width = 0;
	args->has_prec = 0;
	args->prec = 0;
	args->zero_prec = 0;
}
