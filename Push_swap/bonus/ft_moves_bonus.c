/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:36:44 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/28 14:21:16 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_new_move(t_moves **moves, char *move)
{
	t_moves	*new;

	new = (t_moves *)malloc(sizeof(t_moves));
	/* if (!new)
		return; */
	new->move = move;
	new->next = NULL;
	new->prev = NULL;
	ft_move_add(moves, new);
}

void	ft_move_add(t_moves **moves, t_moves *node)
{
	t_moves	*tmp;

	if (*moves == NULL)
	{
		*moves = node;
		return ;
	}
	tmp = ft_lastm(*moves);
	tmp->next = node;
	node->prev = tmp;
}

t_moves	*ft_lastm(t_moves *moves)
{
	while (moves->next)
		moves = moves->next;
	return (moves);
}

void	ft_free_moves(t_moves **moves)
{
	t_moves	*temp;

	if (*moves == NULL)
		return ;
	temp = *moves;
	*moves = temp->next;
	free(temp);
	if (*moves != 0)
		ft_free_moves(moves);
}
