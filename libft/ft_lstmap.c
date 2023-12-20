/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:59 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 14:47:09 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_lstmap
    Purpose: Creates a new list by applying a function,
	 to each element of an existing list.
    How it works:
       - Iterates through the original list.
       - Applies the function 'f' to the content of each element.
       - Creates a new element with the modified content.
       - Adds the new element to the new list.
       - If any step fails, it clears the new list and returns NULL.
*/
#include "libft.h"

static t_list	*create_new_node(void *content, void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node && content)
		del(content);
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = create_new_node(new_content, del);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_node;
		else
			ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*#include <stdio.h>
void	*double_content(void *content)
{
	int *new_content = malloc(sizeof(int));
	if (!new_content)
		return (NULL);
	*new_content = (*(int *)content) * 2;
	return (new_content);
}
int main(void)
{
	t_list *list = NULL;
	t_list *mapped_list = NULL;
	int a = 1;
	int b = 2;
	int c = 3;

	list = ft_lstnew(&a);
	list->next = ft_lstnew(&b);
	list->next->next = ft_lstnew(&c);

	mapped_list = ft_lstmap(list, double_content, free);
	printf("Original list: %d %d %d\n", *(int *)list->content, 
	*(int *)list->next->content, *(int *)list->next->next->content);
	printf("Mapped list: %d %d %d\n", *(int *)mapped_list->content, 
	*(int *)mapped_list->next->content, *(int *)mapped_list->next->next->content);
	ft_lstclear(&list, NULL);
	ft_lstclear(&mapped_list, free);
	return (0);
}*/