/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:07 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:20 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_memccpy
    Purpose: Copies bytes from a source memory area
	to a destination memory area, 
	stopping after a specified character
	is copied or a number of bytes
	have been copied.
    How it works:
       - Casts the source and destination pointers to unsigned char pointers.
       - Initializes a counter 'i' to keep track of the copied bytes.
       - Uses a while loop to copy bytes from source to destination.
       - Checks if the copied byte is equal to the specified character.
       - If it is, returns a pointer to the byte following the copied character 
         in the destination.
       - If the specified character is not found after copying 'n' bytes, 
         returns NULL.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
    char src[15] = "Hello, World!";
    char dst[15];
    void *cpy;
    cpy = ft_memccpy(dst, src, ',', 15);

    if (cpy)
    {
        printf("Character ',' was found and copied.\n");
        printf("Copied string: %s\n", dst);
    }
    else
        printf("Character ',' was not found in the first 15 bytes.\n");
    return (0);
}*/