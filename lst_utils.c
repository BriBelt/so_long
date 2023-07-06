/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:03:36 by bbeltran          #+#    #+#             */
/*   Updated: 2023/07/06 15:10:39 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *lstlast(t_map *map)
{
	if (!map)
		return (0);
	while (map->next != NULL)
		map = map->next;
	return (map);
}

int	mapsize(t_map *map)
{
	int		i;
	t_map	*curr;

	curr = map;
	i = 0;
	if (!curr)
		return (0);
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

/* Frees the map list. */
void	free_map(t_map **map)
{
	t_map	*aux;

	while (*map)
	{
		aux = *map;
		*map = (*map)->next;
		free(aux);
	}
	free(map);
}

/* Creates nodes(row) for the map list. */
t_map	*create_row(char *row, int rownum)
{
	t_map	*new;

	if (!row || row == NULL)
		return (0);
	new = malloc(sizeof(t_map));
	if (!new)
		return (0);
	new->data = row;
	new->next = NULL;
	new->cols = 0;
	new->rows = 0;
	new->index = rownum;
	new->collectibles = 0;
	new->exit = 0;
	new->player = 0;
	return (new);
}

/* Inserts a new node(row) into the map list. */
void	insert_row(t_map **head, char *row, int rownum)
{
	t_map	*ptr;
	t_map	*node;

	node = create_row(row, rownum);
	if (!node ||node == NULL)
		return ;
	if (*head == NULL)
		*head = node;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = node;
	}
}
