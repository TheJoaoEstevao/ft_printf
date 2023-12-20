/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:01:02 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:15 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_strrchr
    Purpose: Locate the last occurrence 
	of a character (c) in a string (s).
    How it works:
       - Initializes a pointer (last) to NULL,
	    which will store the location of the found character.
       - Iterates through the string (s).
       - If the current character matches (c),
	   updates 'last' to point to the current character.
       - Continues to check until the end of
	    the string to find the last occurrence.
       - If (c) is found, returns a pointer to the last occurrence.
       - If (c) is not found, returns NULL.
       - Also checks for (c) being the null-terminator 
	   and updates 'last' accordingly.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		last = (char *)s;
	return (last);
}
/*#include <stdio.h>
int main(void)
{
    char *str = "Hello, World! Programming is fun!";
    char c1 = 'o';
    char c2 = 'z';

    char *result1 = ft_strrchr(str, c1);
    if (result1)
        printf("Last occurrence of '%c': %s\n", c1, result1);
    else
        printf("Character '%c' not found.\n", c1);
    char *result2 = ft_strrchr(str, c2);
    if (result2)
        printf("Last occurrence of '%c': %s\n", c2, result2);
    else
        printf("Character '%c' not found.\n", c2);
    return 0;
}*/