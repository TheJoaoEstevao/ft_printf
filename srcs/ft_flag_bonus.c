/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:08:21 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/15 21:26:34 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_format_plus(char	*cstr, t_format *f)
{
	int		nb;
	char	*cfstr;

	if ((f->plus || f->space) && (f->type == 'd' || f->type == 'i'))
	{
		nb = ft_atoi(cstr);
		if (nb < 0)
			return (cstr);
		cfstr = ft_calloc(sizeof(char), 2);
		if (!cfstr)
			return (NULL);
		if (f->plus)
			cfstr[0] = '+';
		else
			cfstr[0] = ' ';
		cfstr = ft_strcat(cfstr, cstr);
		if (!cfstr)
			return (NULL);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

static char	*ft_format_hash(char	*cstr, t_format *f)
{
	char	*cfstr;

	if (f->hash && (f->type == 'x' || f->type == 'X'))
	{
		cfstr = ft_calloc(sizeof(char), 3);
		if (!cfstr)
			return (NULL);
		cfstr[0] = '0';
		if (cstr[0] != '0')
		{
			cfstr[1] = f->type;
			cfstr = ft_strcat(cfstr, cstr);
			if (!cfstr)
				return (NULL);
		}
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

char	*ft_convert_flag(char	*cstr, t_format *f)
{
	cstr = ft_format_plus(cstr, f);
	if (!cstr)
		return (NULL);
	cstr = ft_format_hash(cstr, f);
	if (!cstr)
		return (NULL);
	return (cstr);
}

int	ft_check_null_empty(char *cstr, t_format *f)
{
	int	spaces;

	if (!cstr || cstr[0] == '\0')
	{
		if (f->width > 0)
		{
			spaces = f->width;
			while (spaces--)
				ft_putchar_fd(' ', 1);
			return (f->width);
		}
		return (0);
	}
	return (-1);
}

int	ft_str_width(char *cstr, t_format *f, int str_len)
{
	int	spaces;

	spaces = f->width - str_len;
	ft_putstr_fd(cstr, 1);
	while (spaces-- > 0)
		ft_putchar_fd(' ', 1);
	return (f->width);
}
