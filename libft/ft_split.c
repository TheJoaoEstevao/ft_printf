/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro3 <jopedro3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:33 by jopedro3          #+#    #+#             */
/*   Updated: 2023/10/04 13:13:19 by jopedro3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Function: ft_split
    Purpose: Splits a string 's' using 'c' as a delimiter.
    How it works:
       - Counts words in 's' separated by 'c'.
       - Allocates memory for 'arr' to store words.
       - Uses 'str_alloc' to allocate/copy words.
       - Increments 'j' to track position in 's'.
       - If allocation fails, frees memory, returns NULL.
       - Sets the last element of 'arr' to NULL.
    Helper Functions:
       - count_words: Counts words in 's'.
       - str_alloc: Allocates and copies a word.
       - free_array: Frees memory in 'arr' if error.
    Note: 
       - A word is a sequence not containing 'c'.
       - Handles multiple consecutive delimiters.
       - 'arr' is NULL-terminated.
*/
#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*str_alloc(const char *s, size_t *j, char c)
{
	size_t	len;
	char	*str;
	size_t	i;

	len = 0;
	i = 0;
	while (s[*j] == c)
		(*j)++;
	while (s[*j + len] && s[*j + len] != c)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[(*j)++];
	str[i] = '\0';
	return (str);
}

static void	free_array(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	int		words;
	size_t	j;
	char	**arr;

	index = 0;
	j = 0;
	words = count_words(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!s || !arr)
		return (NULL);
	while (index < (size_t)words)
	{
		arr[index] = str_alloc(s, &j, c);
		if (!arr[index])
		{
			free_array(arr, index);
			return (NULL);
		}
		index++;
	}
	arr[index] = NULL;
	return (arr);
}
/*#include <stdio.h>
int main(void)
{
    char **result;
    size_t i;

    result = ft_split("Hello  World! 42", ' ');
    i = 0;
    while (result[i])
    {
        printf("Word[%zu]: %s\n", i, result[i]);
        i++;
    }
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}*/