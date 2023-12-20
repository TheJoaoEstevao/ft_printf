/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:43 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:45:44 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Function: ft_strjoin

Purpose: 
  - Concatenates two strings (`s1` and `s2`) into a new string, 
    creating a fresh string that is the combination of both.

 How it works:
 1. Checks if either of the input strings (`s1` or `s2`) is NULL, 
 and returns NULL if true to prevent undefined behavior.
 2. Allocates memory for the new string (`joined_str`). 
    The size is the sum of the lengths of `s1` and `s2`,
	 plus 1 for the null-terminator.
 3. If memory allocation fails, returns NULL.
 4. Copies characters from `s1` into `joined_str`.5.
  Appends characters from `s2` to `joined_str`.
 6. Adds a null-terminator at the end of `joined_str`.
 7. Returns the concatenated string (`joined_str`).
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	joined_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (NULL);
	len = 0;
	while (*s1)
		joined_str[len++] = *s1++;
	while (*s2)
		joined_str[len++] = *s2++;
	joined_str[len] = '\0';
	return (joined_str);
}
/*#include <stdio.h>
int main(void)
{
    char s1[] = "Hello, ";
    char s2[] = "World!";
    char *joined_str;

    joined_str = ft_strjoin(s1, s2);
    if (!joined_str)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Joined string: %s\n", joined_str);
    free(joined_str);
    return 0;
}*/