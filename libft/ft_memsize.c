/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:27:02 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/21 09:27:03 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_memsize(void *ptr)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *) ptr;
	while (*str++)
		n++;
	return (n);
}
