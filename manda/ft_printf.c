/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:55:40 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/19 15:53:07 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static char	*ft_get_format_str(const char *str, va_list ap, t_format *f)
{
	int		i;
	char	*fstr;

	fstr = ft_format_str(NULL, '%', 0);
	if (!fstr)
		return (NULL);
	i = 1;
	ft_reset_format(f);
	while (str[i])
	{
		if (!ft_set_format(str[i], ap, f))
		{
			free(fstr);
			return (NULL);
		}
		fstr = ft_format_str(fstr, str[i], i);
		if (!str)
			return (NULL);
		if (f->type)
			return (fstr);
		i++;
	}
	free(fstr);
	return (NULL);
}


static	int	ft_print_format(va_list ap, t_format *f)
{
	int		n;
	char	*cstr;

	if (f->type == '%')
		return (ft_percent());
	if (f->type == 'c')
		return (ft_char(ap, f));
	if (f->type == 'p')
		return (ft_pointer(ap, f));
	cstr = ft_convert_type(ap, f);
	n = ft_print_str(cstr, f);
	free(cstr);
	return (n);
}

static int	ft_core(const char *str, va_list ap)
{
	char		*fstr;
	int			len;
	t_format	f;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			fstr = ft_get_format_str(str, ap, &f);
			if (fstr)
			{
				len += ft_print_format(ap, &f);
				str += ft_strlen(fstr);
				free(fstr);
			}
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
			str++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	if (str == NULL)
		return (0);
	va_start(ap, str);
	len = ft_core(str, ap);
	va_end(ap);
	return (len);
}
