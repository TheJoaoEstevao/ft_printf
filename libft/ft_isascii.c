/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:32 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:44 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_isascii
    Purpose: Check if a character is an ASCII character.
    How it works:
       - Checks if 'c' is within the ASCII range (0 to 127 inclusive).
       - Returns 1 if 'c' is an ASCII character, otherwise 0.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*#include <stdio.h>
int main(void)
{
    int test_char1 = 65;
    int test_char2 = -1;
    int test_char3 = 128;
    printf("Is %d an ASCII character? (Expect 1):
	 %d\n", test_char1, ft_isascii(test_char1));
    printf("Is %d an ASCII character? (Expect 0):
	 %d\n", test_char2, ft_isascii(test_char2));
    printf("Is %d an ASCII character? (Expect 0):
	 %d\n", test_char3, ft_isascii(test_char3));
    return 0;
}*/