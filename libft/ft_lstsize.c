/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:05 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:17 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_lstsize
    Purpose: Counts and returns the number of nodes in a linked list.
    How it works:
       - Initializes a counter to keep track of the number of nodes.
       - Traverses through the linked list using a while loop.
       - For each node encountered, increments the counter.
       - Moves to the next node until the end of the list is reached.
       - Returns the final count of nodes in the list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*#include <stdio.h>
int main(void)
{
    t_list *node1;
    t_list *node2;
    t_list *node3;
    int size;

    node1 = ft_lstnew("Node 1");
    node2 = ft_lstnew("Node 2");
    node3 = ft_lstnew("Node 3");

    if (node1 && node2 && node3)
    {
        node1->next = node2;
        node2->next = node3;
    }
    size = ft_lstsize(node1);
    printf("List size: %d\n", size);
    free(node1);
    free(node2);
    free(node3);
    return (0);
}*/
