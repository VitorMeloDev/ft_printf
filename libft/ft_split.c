/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 21:36:09 by marvin            #+#    #+#             */
/*   Updated: 2026/06/06 21:48:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arrays(char **arr);
static char	*vm_get_word(char const *s, char c, char **arr);
static int	vm_count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		id;

	if (!s)
		return (NULL);
	words = vm_count_words(s, c);
	arr = ft_calloc(sizeof(char *), words + 1);
	if (!arr)
		return (NULL);
	id = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			arr[id] = vm_get_word(s, c, arr);
			id++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	arr[id] = NULL;
	return (arr);
}

static void	free_arrays(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*vm_get_word(char const *s, char c, char **arr)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	str = ft_substr(s, 0, len);
	if (!str)
		return (free_arrays(arr), NULL);
	return (str);
}

static int	vm_count_words(char const *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 1;
	while (*s != '\0')
	{
		if (*s != c && word == 1)
		{
			count++;
			word = 0;
		}
		if (*s == c)
		{
			word = 1;
		}
		s++;
	}
	return (count);
}
