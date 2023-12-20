/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:35 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:48 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_strchr
    Purpose: Finds the first occurrence of 'c' in 's'.
    How it works:
       - Converts 'c' to char and assigns to 'ch'.
       - Iterates through 's' until '\0' or 'ch' found.
       - If 'ch' found, returns pointer to its location.
       - If 'ch' is '\0', returns pointer to string end.
       - If 'ch' not found, returns NULL.
    Note: 
       - 's' is the string to be scanned.
       - 'c' is the character to be located.
       - Returns pointer to matched char or NULL.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
    char str[] = "Hello, World!";
    char c = 'W';
    char *result;

    result = ft_strchr(str, c);
    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Character '%c' not found in string.\n", c);
    return (0);
}*/