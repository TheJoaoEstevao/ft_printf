/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:56:32 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/19 18:56:35 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*buf;
	char			*temp;

	i = 0;
	buf = (char *) dest;
	temp = (char *) src;
	while (i < n)
	{
		*buf++ = *temp++;
		i++;
	}
	return (dest);
}
