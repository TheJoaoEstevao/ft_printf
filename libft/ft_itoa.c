/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:55:20 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/19 18:55:24 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fill_str(char *str, int n, int len)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	while (n)
	{
		len--;
		str[len] = '0' + sign * (n % 10);
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_count(n);
	if (n < 0)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
		ft_fill_str(str, n, len);
	return (str);
}
