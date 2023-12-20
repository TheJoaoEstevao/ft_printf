/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:27:20 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/15 21:10:28 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_align_left(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		plen;

	i = 0;
	plen = ft_printlen(cstr);
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	if (!cfstr)
		return (NULL);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (i < f->width)
	{
		if (i < plen && (f->type == 's' && *cstr == 0))
			cfstr[i] = ' ';
		else if (i < plen)
			cfstr[i] = cstr[i];
		else
			cfstr[i] = ' ';
		i++;
	}
	free(cstr);
	return (cfstr);
}

static int	ft_fill_prefix(char *cfstr, int i, int n, t_format *f)
{
	while (i < f->width - n)
	{
		if (f->zero && (!f->dot || f->pcs < 0))
			cfstr[i] = '0';
		else
			cfstr[i] = ' ';
		i++;
	}
	return (i);
}

static char	*ft_align_right(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	plen = ft_printlen(cstr);
	if (!cfstr)
		return (NULL);
	if (cstr[0] == '-' && (f->zero && (!f->dot || f->pcs < 0)))
	{
		cfstr[i++] = cstr[j++];
		f->width++;
	}
	i = ft_fill_prefix(cfstr, i, plen, f);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (j < plen)
		cfstr[i++] = cstr[j++];
	free(cstr);
	return (cfstr);
}

char	*ft_convert_width(char	*cstr, t_format *f)
{
	char	*cfstr;

	if (f->width <= ft_strlen(cstr))
		return (cstr);
	if (f->minus)
		cfstr = ft_align_left(cstr, f);
	else
		cfstr = ft_align_right(cstr, f);
	if (!cfstr)
		return (NULL);
	return (cfstr);
}
