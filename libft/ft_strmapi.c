/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:53 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 13:29:05 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_strmapi
    Purpose: Creates a new string by applying a
	 function to each character of a given string.
    How it works:
        1. Checks if the input string (s) or function
		(f) is NULL, if so, returns NULL.
        2. Allocates memory for a new string (new_str)
		 with the same length as (s) plus one for the null-terminator.
        3. If memory allocation fails, returns NULL.
        4. Iterates through each character of the string (s).
        5. Applies the function (f) to each character and its index,
		 storing the result in (new_str).
        6. Adds a null-terminator at the end of (new_str).
        7. Returns the new string (new_str).
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*#include <stdio.h>
int main(void)
{
    char *str = "Hello, World!";
    char *new_str;
    unsigned int i = 0;

    new_str = ft_strmapi(str, example_function);

    if (new_str)
    {
        printf("Original: %s\n", str);
        while (new_str[i] != '\0')
        {
            if (i % 2 != 0)
            {
                new_str[i] = new_str[i] + 1;
            }
            i++;
        }
        printf("Mapped  : %s\n", new_str);
        free(new_str);
    }
    else
        printf("Memory allocation failed\n");
    return 0;
}*/