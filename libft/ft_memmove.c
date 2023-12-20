/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:16 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:29 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_memmove
    Purpose: Safely copies 'len' bytes from
	 source to destination memory block, even when they overlap.
    How it works:
       - Checks if both source and destination
	    pointers are NULL, if true, returns NULL.
       - Casts the input pointers to unsigned
	    char pointers for byte-wise copying.
       - If destination is before source in memory,
	    copies from start to end.
       - If destination is after source, copies
	    from end to start to avoid overwriting.
       - Returns the original destination pointer.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
/*#include <stdio.h>
int main(void)
{
    char str[30] = "Hello, World!";

    // Use ft_memmove to shift "World!" 6 positions right within str
    ft_memmove(str + 7, str + 7 - 6, 6);
    str[13] = '\0';
    printf("Modified string: %s\n", str); 
    return (0);
}*/