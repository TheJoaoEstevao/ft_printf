/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_tools_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:16:19 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/13 18:01:16 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_istype(char c)
{
	char	*ptr;

	ptr = F_TYPE;
	while (*ptr)
		if (*ptr++ == c)
			return (1);
	return (0);
}

int	ft_set_star(char c, va_list ap, t_format *f)
{
	int		star;

	if (c != '*')
		return (0);
	if (f->dot)
	{
		star = (va_arg(ap, int));
		f->pcs = star;
	}
	else
	{
		star = (va_arg(ap, int));
		if (star < 0)
		{
			f->minus = 1;
			star *= -1;
		}
		f->width = star;
	}
	return (1);
}

int	ft_set_format(char c, va_list ap, t_format *f)
{
	if (ft_set_star(c, ap, f))
		return (1);
	else if (f->dot && ft_isdigit(c))
		f->pcs = (f->pcs * 10) + (c - '0');
	else if (ft_istype(c))
		f->type = c;
	else if (c == '-')
		f->minus = 1;
	else if (c == '+')
		f->plus = 1;
	else if (c == ' ')
		f->space += 1;
	else if (c == '0' && f->width == 0)
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == '.')
		f->dot = 1;
	else if (ft_isdigit(c))
		f->width = (f->width * 10) + (c - '0');
	else
		return (0);
	return (1);
}

void	ft_reset_format(t_format *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->dot = 0;
	f->width = 0;
	f->pcs = 0;
	f->type = 0;
}

char	*ft_format_str(char *fstr, char c, int i)
{
	if (!fstr)
		fstr = ft_calloc(sizeof(char), i + 2);
	else
		fstr = ft_realloc(fstr, i + 2);
	if (!fstr)
		return (NULL);
	fstr[i] = c;
	return (fstr);
}
