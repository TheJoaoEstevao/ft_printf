/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:26:34 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/21 09:26:37 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	baselen(size_t nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_inttohex(size_t nb)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	str = ft_calloc(sizeof(char), baselen(nb) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	i = 0;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	ft_strrev(str);
	return (str);
}
