/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:53:48 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/19 18:53:51 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buf;

	buf = malloc(n * size);
	if (!buf)
		return (NULL);
	if (buf)
		ft_bzero(buf, n * size);
	return (buf);
}
