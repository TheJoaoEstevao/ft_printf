/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:59 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:12 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_strnstr
    Purpose: Locate a substring (needle)
	 in a string (haystack), examining only the first 'len' characters.
    How it works:
       - If the needle is an empty string,
	    the function returns the haystack.
       - Iterates through the haystack,
	    checking each substring of length equal to the needle's length.
       - For each substring, compares it with the needle character by character.
       - If a match is found, returns
	    a pointer to the first character of the substring in the haystack.
       - If no match is found after examining 'len' characters, returns NULL.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len1;
	size_t	len2;
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	len1 = 0;
	while (haystack[len1] && len1 + needle_len <= len)
	{
		len2 = 0;
		while (haystack[len1 + len2] == needle[len2]
			&& haystack[len1 + len2] && needle[len2])
			len2++;
		if (!needle[len2])
			return ((char *)(haystack + len1));
		len1++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
    char *haystack = "The quick brown fox jumps over the lazy dog";
    char *needle1 = "fox";
    char *needle2 = "cat";
    size_t len = 20;

    char *result1 = ft_strnstr(haystack, needle1, len);
    if (result1)
        printf("Found: %s\n", result1);
    else
        printf("Did not find: %s\n", needle1);
    char *result2 = ft_strnstr(haystack, needle2, len);
    if (result2)
        printf("Found: %s\n", result2);
    else
        printf("Did not find: %s\n", needle2);
	return 0;
}*/