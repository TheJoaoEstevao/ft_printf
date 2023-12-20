/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:27:28 by jestevao          #+#    #+#             */
/*   Updated: 2023/11/21 09:27:29 by jestevao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		n1;
	int		n2;

	i = 0;
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	s1 = ft_realloc((void *) s1, n1 + n2 + 1);
	if (!s1)
		return (NULL);
	while (i < n1)
		i++;
	while (i < n2 + n1)
	{
		s1[i] = s2[i - n1];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
