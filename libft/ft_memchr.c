/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:09 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:22 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_memchr
    Purpose: Locates the first occurrence of a specified character in a block 
             of memory during a specified number of bytes.
    How it works:
       - Casts the input pointer to an unsigned char pointer.
       - Initializes a counter 'len' to keep track of checked bytes.
       - Uses a while loop to check each byte of the memory block.
       - If the byte matches the specified character, returns a pointer to it.
       - If the character is not found after checking 'n' bytes, returns NULL.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		if (ptr[len] == (unsigned char)c)
			return (ptr + len);
		len++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
    char arr[15] = "Hello, World!";
    char *cpy;
    cpy = (char *)ft_memchr(arr, 'l', 10);
    if (cpy)
        printf("Character 'l' was found at position: %ld\n", cpy - arr);
    else
        printf("Character 'l' was not found in the first 10 bytes.\n");
    return (0);
}*/