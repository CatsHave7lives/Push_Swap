/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:07:09 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/29 03:37:44 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static size_t	ft_wordcount(char const *s, char delimiter)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delimiter)
			i++;
		if (s[i])
		{
			word_count++;
			while (s[i] && s[i] != delimiter)
				i++;
		}
	}
	return (word_count);
}

static size_t	ft_nextword(char const *s, size_t i, char c, size_t *next)
{
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
		*next = i;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (len > sub_len)
		len = sub_len;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	return (ft_strlcpy(sub, s + start, len + 1), sub);
}

static int	ft_strsplit(char const *s, char c, char **array)
{
	size_t	i;
	size_t	row;
	size_t	next;

	i = 0;
	row = 0;
	while (s[i])
	{
		i = ft_nextword(s, i, c, &next);
		if (i > next)
		{
			array[row] = ft_substr(s, next, i - next);
			if (!array[row])
			{
				while (row-- > 0)
					free(array[row]);
				return (free(array), NULL);
			}
			row++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	array[row] = NULL;
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!word_count)
		return (array[0] = NULL, array);
	if (!ft_strsplit(s, c, array))
		return (NULL);
	return (array);
}
