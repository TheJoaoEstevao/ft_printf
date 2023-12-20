/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:55 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:05 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_lstlast
    Purpose: Find the last element of a linked list.
    How it works:
       - Checks if the list is not empty.
       - Traverses the list until it finds an element with no next element.
       - Returns the last element found.
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*#include <stdio.h>
int main(void)
{
    t_list *list = NULL;
    t_list *last_element;
    char *str1 = "First";
    char *str2 = "Last";

    list = ft_lstnew(str1);
    if (!list)
    {
        printf("Failed to create list!\n");
        return (1);
    }
    ft_lstadd_back(&list, ft_lstnew(str2));
    last_element = ft_lstlast(list);
    if (last_element)
        printf("Last element: %s\n", (char *)last_element->content);
    else
        printf("List is empty!\n");
    ft_lstclear(&list, free);
    return (0);
}*/