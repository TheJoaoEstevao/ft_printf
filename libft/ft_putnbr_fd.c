/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:27 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:41 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_putnbr_fd
    Purpose: Outputs the integer 'n'
	 to the given file descriptor 'fd'.
    How it works:
       - Handles the edge case of the
	    smallest integer, which cannot be negated.
       - If 'n' is negative, outputs
	    a minus sign and makes 'n' positive.
       - Recursively calls itself to
	    handle each digit of 'n' if 'n' is greater than 9.
       - Outputs the last digit of 'n'
	    by converting it to a character and writing it to 'fd'.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}
/*#include <stdio.h>
int main(void)
{  
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    return (0);
}*/