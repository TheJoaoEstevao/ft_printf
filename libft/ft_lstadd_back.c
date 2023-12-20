/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:42 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:51 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_lstadd_back
    Purpose: Add a new element to the end of a linked list.
    How it works:
       - Checks if 'lst' or 'new' is NULL, returning if true.
       - If '*lst' is NULL, sets '*lst' to 'new' and returns.
       - Finds the last element of the list using ft_lstlast.
       - Sets the 'next' pointer of the last element to 'new'.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*#include <stdio.h>
int main(void)
{
    t_list *lst = NULL;
    t_list *new_elem1;
    t_list *new_elem2;

    new_elem1 = ft_lstnew("Hello");
    new_elem2 = ft_lstnew("World");
    ft_lstadd_back(&lst, new_elem1);
    ft_lstadd_back(&lst, new_elem2);
    while (lst)
    {
        printf("%s ", (char *)lst->content);
        lst = lst->next;
    }
    printf("\n");
    return (0);
}*/