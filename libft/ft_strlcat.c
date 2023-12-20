/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:46 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:45:59 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_strlcat
    Purpose: Concatenates two strings (dst and src) safely,
	 ensuring that the resulting string is null-terminated.
    How it works:
        1. Finds the lengths of dst and src using ft_strlen.
        2. Checks if size (maximum length to concatenate)
		is less than or equal to dst_len. If true, returns
		 the sum of size and src_len.
        3. Initializes len to 0, which will be used to 
		iterate through src.
        4. Iterates through src, copying characters to dst,
		 ensuring not to exceed the size limit.
        5. Null-terminates the concatenated string in dst.
        6. Returns the total length of the string that 
		would have been created if there were enough space.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	len = 0;
	while (src[len] && (dst_len + len + 1) < size)
	{
		dst[dst_len + len] = src[len];
		len++;
	}
	dst[dst_len + len] = '\0';
	return (dst_len + src_len);
}
/*#include <stdio.h>
int main(void)
{
    char dest[20] = "Hello";
    char *src = " World!";
    size_t size = 20;
    size_t result;

    result = ft_strlcat(dest, src, size);
    printf("Result: %zu\n", result);
    printf("Concatenated string: %s\n", dest);
    return 0;
}*/