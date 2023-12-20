/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:57:33 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:02 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_lstiter
    Purpose: Applies a function to the content of each element in a list.
    How it works:
       - Checks if 'lst' and 'f' are not NULL to proceed.
       - Iterates through each element in the list.
       - Applies function 'f' to the content of each element.
       - Does not return anything.
       - Note: The list navigation is done using 'lst = lst->next'.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*#include <stdio.h>
void to_uppercase(void *content)
{
    char *str;

    str = (char *)content;
    while (*str)
    {
        *str = ft_toupper(*str);
        str++;
    }
}
int main(void)
{
    t_list *element;
    char str[] = "hello";
    element = ft_lstnew(str);

    if (!element)
    {
        printf("Failed to create list element!\n");
        return (1);
    }
    printf("Before: %s\n", (char *)element->content);
    ft_lstiter(element, to_uppercase);
    printf("After: %s\n", (char *)element->content);
    free(element);
    return (0);
}*/