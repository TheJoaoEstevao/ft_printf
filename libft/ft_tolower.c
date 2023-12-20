/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:01:10 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 13:20:46 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_tolower
    - Converts an uppercase character to lowercase.
    - Checks if 'c' is an uppercase letter (between 'A' and 'Z').
    - If true, adds 32 to 'c' to convert it to lowercase.
    - Returns the possibly modified character 'c'.
*/
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*#include <stdio.h>
int main(void)
{
    int c = 'A';
    int lower_c = ft_tolower(c);
    printf("Original: %c\n", c);
    printf("Lowercase: %c\n", lower_c);
    return 0;
}*/