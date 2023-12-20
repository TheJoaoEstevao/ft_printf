/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:58:30 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:36 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_isalnum
    Purpose: Check if a character is alphanumeric.
    How it works:
       - Utilizes ft_isalpha and ft_isdigit to check if 'c' is a letter or digit.
       - Returns 1 if 'c' is alphanumeric, otherwise 0.
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*#include <stdio.h>
int main(void)
{
    char test_char1 = 'a';
    char test_char2 = '5';
    char test_char3 = '!';
	
    printf("Is it '%c' alphanumeric? (Expect 1): %d\n",
	 test_char1, ft_isalnum(test_char1));
    printf("Is it '%c' alphanumeric? (Expect 1): %d\n", test_char2,
	 ft_isalnum(test_char2));
    printf("Is it '%c' alphanumeric? (Expect 0): %d\n", test_char3,
	 ft_isalnum(test_char3));
    return 0;
}*/