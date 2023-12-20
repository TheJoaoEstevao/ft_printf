/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:19 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:33 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_memset
    Purpose: Fills a block of memory with a specified value.
    How it works:
       - Casts the input pointer to an
	    unsigned char pointer for byte-wise operation.
       - Uses a while loop to traverse 
	   through each byte of the memory block.
       - Assigns the specified value (c) to each byte.
       - Decreases the length (len) until it becomes zero.
       - Returns the original pointer to the memory block.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}
/*#include <stdio.h>
int main(void)
{
    char str[20] = "Hello, World!";  
    // Use ft_memset to fill the first 5 bytes of str with '-'
    ft_memset(str, '-', 5);
    printf("Modified string: %s\n", str);
    return (0);
}*/