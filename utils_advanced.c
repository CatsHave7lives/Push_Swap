/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_advanced.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:47:30 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/24 09:15:59 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dup;

	s1_len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dup)
		return (NULL);
	return (ft_strlcpy(dup, s1, s1_len + 1), dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

// char	**arg_check(int ac,char **av)
// {
// 	if (ac == 1)
// 		exit (EXIT_FAILURE);
// 	if (ac == 2)
// 		*av = 
// }
