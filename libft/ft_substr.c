/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:58:11 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/19 18:58:41 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*setstr(char const *s, char *str, int start, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i + start] && i < n)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	if (start > (unsigned int) ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else
		slen = ft_strlen(s) - start;
	if (len < slen)
		slen = len;
	str = malloc(sizeof(char) * slen + 1);
	if (!str)
		return (NULL);
	str = setstr(s, str, start, slen);
	return (str);
}
