/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:47 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:54 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_lstclear
    Purpose: Frees memory of the entire linked list and sets the list to NULL.
    How it works:
       - Checks if 'lst', '*lst', and 'del' are not NULL to proceed.
       - Iterates through each element in the list.
       - For each element, it saves the next node, deletes the current node,
         and moves to the next node.
       - Finally, it sets the original list pointer to NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next_node;

	if (!lst || !*lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next_node = temp->next;
		ft_lstdelone(temp, del);
		temp = next_node;
	}
	*lst = NULL;
}
/*#include <stdio.h>
void del(void *content)
{
    free(content);
}
int main(void)
{
    t_list *lst = NULL;
    t_list *new_elem1;
    t_list *new_elem2;
    new_elem1 = ft_lstnew(strdup("Hello"));
    new_elem2 = ft_lstnew(strdup("World"));
    ft_lstadd_front(&lst, new_elem1);
    ft_lstadd_front(&lst, new_elem2);
    ft_lstclear(&lst, del);
    if (!lst)
        printf("List is cleared!\n");
    else
        printf("List is NOT cleared!\n");
    return (0);
}*/