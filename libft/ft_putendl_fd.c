/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:25 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:39 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_putendl_fd
    Purpose: Writes a string followed by a newline
	 to a given file descriptor.
    How it works:
       - First, checks if the string (s) is NULL.
	    If it is, the function returns without doing anything.
       - Calls ft_putstr_fd to write the string 
	   (s) to the file descriptor (fd).
       - Then, writes a newline character ("\n")
	    to the file descriptor (fd) using the write system call.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*#include <stdio.h>
int main(void)
{
    ft_putendl_fd("Hello, World!", 1);
    return (0);
}*/