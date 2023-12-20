/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:26:40 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/13 16:30:56 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int	ft_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_char_padding(int width, int minus_flag)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (minus_flag == 0)
	{
		while (i < width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_char(va_list ap, t_format *f)
{
	char	c;
	int		width;
	int		n;

	c = (char)va_arg(ap, int);
	if (f->width > 0)
		width = f->width;
	else
		width = 1;
	n = ft_char_padding(width, f->minus);
	ft_putchar_fd(c, 1);
	n++;
	if (f->minus)
	{
		while (n < width)
		{
			ft_putchar_fd(' ', 1);
			n++;
		}
	}
	return (n);
}

int	ft_pointer(va_list ap, t_format *f)
{
	char	*cstr;
	int		n;

	cstr = ft_convert_p((size_t)va_arg(ap, void *));
	cstr = ft_convert_flag(cstr, f);
	cstr = ft_convert_width(cstr, f);
	n = ft_print_str(cstr, f);
	free(cstr);
	return (n);
}
