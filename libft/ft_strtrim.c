/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:01:04 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:18 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_strtrim
    - Trims characters from the start and 
	end of a string (s1) based on a set (set).
    - Utilizes a helper function (ft_is_set) 
	to check if a character is in the set.
    - Finds the start and end indices of the 
	trimmed string by iterating through s1.
    - Creates and returns a new string using
	ft_substr from 'start' to 'end'.
    
    Helper Function: ft_is_set
    - Checks if a character (c) is present in a set of characters (set).
    - Returns 1 if found, otherwise 0.
*/

#include "libft.h"

static int	ft_is_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_set(s1[end - 1], set))
		end--;
	trimmed_str = ft_substr(s1, start, end - start);
	return (trimmed_str);
}
/*#include <stdio.h>
int main(void)
{
    char *str = "****Hello, World!****";
    char *set = "*";
    char *trimmed_str = ft_strtrim(str, set); 
    if (trimmed_str)
    {
        printf("Original: %s\n", str);
        printf("Trimmed : %s\n", trimmed_str);
        free(trimmed_str);
    }
    else
        printf("Failed to trim the string.\n");
    return 0;
}*/