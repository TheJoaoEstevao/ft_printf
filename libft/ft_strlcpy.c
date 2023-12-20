/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:48 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 13:16:47 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_strlcpy
    Purpose: Copies up to size - 1
	 characters from the string src to dst, ensuring null-termination.
    How it works:
        1. Calculates the length of src using ft_strlen.
        2. If size is 0, returns the length of src without copying.
        3. Initializes len to 0, which will be used to iterate through src.
        4. Copies characters from src to dst, ensuring not to exceed size - 1.
        5. Null-terminates the copied string in dst.
        6. Returns the total length of src.
*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	len = 0;
	while (len < size - 1 && src[len])
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (src_len);
}
/*#include <stdio.h>
int main(void)
{
    char dest[20];
    char *src = "Hello World!";
    size_t size = 6;
    size_t result;

    result = ft_strlcpy(dest, src, size);
    printf("Result: %zu\n", result);
    printf("Copied string: %s\n", dest);
    return 0;
}*/