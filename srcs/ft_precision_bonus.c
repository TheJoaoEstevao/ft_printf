/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:10:33 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/13 16:27:49 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_format_pcs_str(char *cstr, t_format *f)
{
	char	*cfstr;

	if ((f->dot && f->pcs == 0)
		|| (IS_LINUX
			&& (ft_strncmp(cstr, S_EMPTY, S_EMPTY_L) == 0 && f->pcs < 6)))
		cfstr = ft_calloc(sizeof(char), 1);
	else
		cfstr = ft_substr(cstr, 0, f->pcs);
	if (!cfstr)
		return (NULL);
	free(cstr);
	return (cfstr);
}

static char	*ft_digit_pcs_fill(char *cfstr, char *cstr, t_format *f)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(cstr);
	i = 0;
	j = 0;
	if (cstr[0] == '-')
	{
		i++;
		j++;
		len--;
		f->pcs++;
	}
	while (i < f->pcs)
	{
		if (i < f->pcs - len)
			cfstr[i] = '0';
		else
			cfstr[i] = cstr[j++];
		i++;
	}
	return (cfstr);
}

static char	*ft_digit_pcs_operation(char *cstr, t_format *f)
{
	char	*cfstr;

	if (cstr[0] == '-')
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 2);
		if (!cfstr)
			return (NULL);
		cfstr[0] = '-';
	}
	else
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 1);
		if (!cfstr)
			return (NULL);
	}
	ft_digit_pcs_fill(cfstr, cstr, f);
	return (cfstr);
}

static char	*ft_format_pcs_digit(char *cstr, t_format *f)
{
	char	*cfstr;

	if (cstr[0] == '0' && f->pcs == 0)
	{
		cfstr = ft_calloc(sizeof(char), f->pcs + 1);
		if (!cfstr)
			return (NULL);
		free(cstr);
		return (cfstr);
	}
	else if (f->pcs >= ft_strlen(cstr))
	{
		cfstr = ft_digit_pcs_operation(cstr, f);
		if (!cfstr)
			return (NULL);
		free(cstr);
		return (cfstr);
	}
	return (cstr);
}

char	*ft_convert_pcs(char *cstr, t_format *f)
{
	char	*cfstr;

	if (!f->dot)
		return (cstr);
	if (f->type == 's' || f->type == 'c')
		cfstr = ft_format_pcs_str(cstr, f);
	else
		cfstr = ft_format_pcs_digit(cstr, f);
	if (!cfstr)
		return (NULL);
	return (cfstr);
}
