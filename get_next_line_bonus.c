/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaber <aessaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:18:54 by aessaber          #+#    #+#             */
/*   Updated: 2025/04/09 22:27:50 by aessaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*load_train_car(int fd, char *train_head)
{
	char	*train_car;
	char	*combined_train;
	ssize_t	boarded_pssngrs;

	train_car = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!train_car)
		return (NULL);
	boarded_pssngrs = 1;
	while (!(ft_strchr(train_head, '\n')) && boarded_pssngrs != 0)
	{
		boarded_pssngrs = read(fd, train_car, BUFFER_SIZE);
		if (boarded_pssngrs == -1)
		{
			free(train_car);
			return (NULL);
		}
		train_car[boarded_pssngrs] = '\0';
		combined_train = ft_strjoin(train_head, train_car);
		free(train_head);
		train_head = combined_train;
	}
	free(train_car);
	return (train_head);
}

static char	*serve_train_departure(char *train_head)
{
	char	*departed_train;
	char	*newln_seat;

	if (!*train_head)
		return (NULL);
	newln_seat = ft_strchr(train_head, '\n');
	if (newln_seat)
		departed_train = ft_substr(train_head, 0, newln_seat - train_head + 1);
	else
		departed_train = ft_strdup(train_head);
	return (departed_train);
}

static char	*update_train_head(char *train_head)
{
	char	*newln_seat;
	char	*left_passengers;

	newln_seat = ft_strchr(train_head, '\n');
	if (newln_seat)
		left_passengers = ft_strdup(newln_seat + 1);
	else
		left_passengers = NULL;
	free(train_head);
	return (left_passengers);
}

char	*get_next_line(int fd)
{
	static char	*train_head;
	char		*departed_train;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(train_head);
		train_head = NULL;
		return (NULL);
	}
	train_head = load_train_car(fd, train_head);
	if (!train_head)
		return (NULL);
	departed_train = serve_train_departure(train_head);
	train_head = update_train_head(train_head);
	return (departed_train);
}
