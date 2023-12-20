/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:49 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:57 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Function: ft_lstdelone
    Purpose: Frees the memory of a single list element.
    How it works:
       - Checks if 'lst' and 'del' are not NULL to proceed.
       - Applies the 'del' function to the content of the list element.
       - Frees the memory of the list element itself.
       - Note: The function does not return anything.
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*#include <stdio.h>
void del(void *content)
{
    free(content);
}
int main(void)
{
    t_list *elem;

    elem = ft_lstnew(strdup("Hello, World!"));

    if (elem && elem->content)
        printf("Element created: %s\n", (char *)elem->content);
    else
        printf("Element NOT created!\n");
    ft_lstdelone(elem, del);
    if (!elem)
        printf("Element is deleted!\n");
    else
        printf("Element is NOT deleted!\n");
    return (0);
}*/