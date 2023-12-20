/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:38 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 13:13:42 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_strdup
    Purpose: Duplicates the string 's1'.
    How it works:
       - Calculates the length of 's1' and adds 1 for '\0'.
       - Allocates memory of size 'len' for the duplicate string 'dup'.
       - If allocation fails, returns NULL.
       - Copies 's1' into 'dup' using ft_memcpy.
       - Returns the pointer to the duplicated string 'dup'.
    Note: 
       - 's1' is the string to be duplicated.
       - Returns a pointer to the duplicated string or NULL.
       - The returned string must be freed with free().
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}
/*#include <stdio.h>
int main(void)
{
    char str[] = "Hello, World!";
    char *duplicate_str;

    duplicate_str = ft_strdup(str);
    if (duplicate_str)
    {
        printf("Original: %s\n", str);
        printf("Duplicate: %s\n", duplicate_str);
        free(duplicate_str);
    }
    else
    {
        printf("Failed to duplicate string.\n");
    }
    return (0);
}*/