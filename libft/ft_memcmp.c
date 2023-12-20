/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:11 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:24 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_memcmp
	Purpose: Compares two blocks of memory and determines if they are equal
			 or if one is lexicographically greater than the other.
	How it works:
	   - Casts the input pointers to
	   unsigned char pointers for byte-wise comparison.
	   - Initializes a counter 'len' to keep track of checked bytes.
	   - Uses a while loop to compare each byte of the two memory blocks.
	   - If a mismatch is found, returns the difference between the two bytes.
	   - If no mismatch is found after checking 'n' bytes, returns 0.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			len;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	len = 0;
	while (len < n)
	{
		if (ptr1[len] != ptr2[len])
			return (ptr1[len] - ptr2[len]);
		len++;
	}
	return (0);
}
/*#include <stdio.h>
int main(void)
{
	char str1[15] = "Hello, World!";
	char str2[15] = "Hello, World!";
	char str3[15] = "Hello, Wxrld!";
	int cpy;

	cpy = ft_memcmp(str1, str2, 10);
	if (cpy == 0)
		printf("str1 and str2 are equal in the first 10 bytes\n");
	else
		printf("str1 and str2 are NOT equal in the first 10 bytes\n");
	cpy = ft_memcmp(str1, str3, 10);
	if (cpy == 0)
		printf("str1 and str3 are equal in the first 10 bytes\n");
	else
		printf("str1 and str3 are NOT equal in the first 10 bytes\n");
	return 0;
}*/