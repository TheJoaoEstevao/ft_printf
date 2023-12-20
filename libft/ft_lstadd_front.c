/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:45 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 12:34:28 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_lstadd_front
    Purpose: Add a new element to the start of a linked list.
    How it works:
       - Checks if 'new' is not NULL to proceed.
       - Assigns the current 'lst' to the 'next' of 'new'.
       - Updates 'lst' to point to 'new', making it the first element.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*#include <stdio.h>
int main(void)
{
    t_list *lst = NULL;
    t_list *new_elem1;
    t_list *new_elem2;

    new_elem1 = ft_lstnew("Hello");
    new_elem2 = ft_lstnew("World");

    ft_lstadd_front(&lst, new_elem1);
    ft_lstadd_front(&lst, new_elem2);

    while (lst)
    {
        printf("%s ", (char *)lst->content);
        lst = lst->next;
    }
    printf("\n");
    return (0);
}*/