/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:41 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 13:13:54 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_striteri
    Purpose: Applies a function 'f' to each 
	character of the string 's'.
             The function 'f' is applied in-place.
    How it works:
       - Checks if 's' or 'f' is NULL, if yes, does nothing.
       - Initializes an index 'i' to 0.
       - Iterates through each character of the string 's'.
       - For each character, applies the function 'f'
	    passing 'i' and the address of 's[i]'.
       - Increments 'i' and repeats until the end of the string.
    Note: 
       - 's' is the string to iterate.
       - 'f' is the function to apply to each character of 's' and its index.
       - 'f' should modify the character in-place.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>
void to_uppercase(unsigned int i, char *ch)
{
    if (*ch >= 'a' && *ch <= 'z')
        *ch = *ch - 'a' + 'A';
    printf("Index: %u, Char: %c\n", i, *ch);
}
int main(void)
{
    char str[] = "hello";

    printf("Before: %s\n", str);
    ft_striteri(str, to_uppercase);
    printf("After: %s\n", str);
    return (0);
}*/