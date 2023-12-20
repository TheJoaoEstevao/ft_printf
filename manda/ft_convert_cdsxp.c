/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_cdsxp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:05:38 by jestevao          #+#    #+#             */
/*   Updated: 2023/12/13 17:54:40 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_convert_c(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

char	*ft_convert_d(int d)
{
	char	*str;

	str = ft_itoa(d);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_convert_s(char *s)
{
	char	*str;

	if (s)
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	else
		str = ft_calloc(sizeof(char), S_EMPTY_L + 1);
	if (!str)
		return (NULL);
	if (s)
		str = ft_memcpy(str, s, ft_strlen(s));
	else
		str = ft_memcpy(str, S_EMPTY, S_EMPTY_L);
	return (str);
}

char	*ft_convert_x(unsigned int nb, int is_upper)
{
	char	*hex;

	hex = ft_inttohex(nb);
	if (!hex)
		return (NULL);
	if (is_upper)
		hex = ft_strtoupper(hex);
	return (hex);
}

char	*ft_convert_p(size_t ptr)
{
	char	*hex;
	char	*pstr;

	if (!ptr)
	{
		pstr = ft_calloc(sizeof(char), P_EMPTY_L + 1);
		if (!pstr)
			return (NULL);
		pstr = ft_memcpy(pstr, P_EMPTY, P_EMPTY_L);
		return (pstr);
	}
	pstr = ft_calloc(sizeof(char), 3);
	if (!pstr)
		return (NULL);
	pstr[0] = '0';
	pstr[1] = 'x';
	hex = ft_inttohex(ptr);
	if (!hex)
		return (NULL);
	pstr = ft_strcat(pstr, hex);
	if (!pstr)
		return (NULL);
	if (hex)
		free(hex);
	return (pstr);
}
