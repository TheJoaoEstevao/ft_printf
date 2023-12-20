/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:02 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:13 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_lstnew
    Purpose: Creates a new list node with given content.
    How it works:
       - Allocates memory for a new node of type t_list.
       - Checks if memory allocation was successful.
       - Assigns the provided content to the new node.
       - Sets the 'next' pointer of the new node to NULL.
       - Returns the new node.
*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*#include <stdio.h>
int main(void)
{
    t_list *node;
    int content = 42;
    node = ft_lstnew(&content);
    if (node && node->content)
        printf("Node content: %d\n", *(int *)node->content);
    else
        printf("Node creation failed.\n");
    free(node);
    return (0);
}*/