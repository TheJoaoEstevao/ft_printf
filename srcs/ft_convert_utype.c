/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:24:59 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/15 21:51:24 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	ft_uilen(unsigned int d)
{
	unsigned int	i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

static char	*ft_uits(unsigned int d)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_uilen(d) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	while (d > 0)
	{
		str[i] = (d % 10) + '0';
		d = d / 10;
		i++;
	}
	return (str);
}

char	*ft_convert_u(unsigned int d)
{
	char	*str;

	str = ft_uits(d);
	if (!str)
		return (NULL);
	ft_strrev(str);
	return (str);
}

char	*ft_convert_type(va_list ap, t_format *f)
{
	char	*str;

	if (f->type == 'c')
		str = ft_convert_c(va_arg(ap, int));
	else if (f->type == 's')
		str = ft_convert_s(va_arg(ap, char *));
	else if (f->type == 'p')
		str = ft_convert_p((unsigned long long) va_arg(ap, void *));
	else if (f->type == 'i' || f->type == 'd')
		str = ft_convert_d(va_arg(ap, int));
	else if (f->type == 'u')
		str = ft_convert_u(va_arg(ap, int));
	else if (f->type == 'x')
		str = ft_convert_x(va_arg(ap, unsigned int), 0);
	else if (f->type == 'X')
		str = ft_convert_x(va_arg(ap, unsigned int), 1);
	else if (f->type == '%')
		str = ft_convert_c('%');
	else
		str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	return (str);
}

int	ft_print_str(char *cstr, t_format *f)
{
	int	n;
	int	result;

	n = ft_strlen(cstr);
	if (f->type == 'd' || f->type == 'i')
	{
		ft_putstr_fd(cstr, 1);
		return (n);
	}
	result = ft_check_null_empty(cstr, f);
	if (result != -1)
		return (result);
	if (f->width > 0 && n < f->width)
		return (ft_str_width(cstr, f, n));
	ft_putstr_fd(cstr, 1);
	return (n);
}
