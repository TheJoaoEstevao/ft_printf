/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:38 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:48 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_isprint
    Purpose: Check if a character is printable.
    How it works:
       - Checks if 'c' is within the ASCII range.
       - Returns 1 if 'c' is printable, otherwise 0.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*#include <stdio.h>
int main(void)
{
    int test_char1 = 'A';
    int test_char2 = 31;
    int test_char3 = ' ';

    printf("Is '%c' printable? (Expect 1): %d\n",
	 test_char1, ft_isprint(test_char1));
    printf("Is '%c' printable? (Expect 0): %d\n",
	 test_char2, ft_isprint(test_char2));
    printf("Is '%c' printable? (Expect 1): %d\n",
	 test_char3, ft_isprint(test_char3));
    return 0;
}*/