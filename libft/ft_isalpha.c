/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:28 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:42 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_isalpha
    Purpose: Check if a character is an alphabet letter.
    How it works:
       - Checks if 'c' is within the ASCII range for uppercase or lowercase 
         letters.
       - Returns 1 if 'c' is a letter, otherwise 0.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*#include <stdio.h>
int main(void)
{
    char test_char1 = 'a';
    char test_char2 = 'Z';
    char test_char3 = '3';
    printf("Is '%c' a letter? (Expect 1): %d\n",
	 test_char1, ft_isalpha(test_char1));
    printf("Is '%c' a letter? (Expect 1): %d\n",
	 test_char2, ft_isalpha(test_char2));
    printf("Is '%c' a letter? (Expect 0): %d\n",
	 test_char3, ft_isalpha(test_char3));
    return 0;
}*/