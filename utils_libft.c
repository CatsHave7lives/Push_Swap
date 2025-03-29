/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:47:30 by aessaber          #+#    #+#             */
/*   Updated: 2025/03/27 10:45:24 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
		dst[i] = src[i++];
	return ((dst[i] = '\0'), ft_strlen(src));
}

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

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		(ft_putchar_fd(s[i], fd), i++);
}
