/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:20:37 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/21 19:52:16 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_close_doors(t_links *queue, t_lem *in)
{
	in->way = queue;
	queue = queue->next;
	while (queue)
	{
		if (queue->name_room->n == 2)
			queue->name_room->door = CLOSE;
		queue = queue->next;
	}
}

void				crt_q(t_links **qu, t_links **q_l, t_lem *in, t_links *tmp)
{
	if (!(*qu))
		ft_error_exit(in, 5);
	tmp = (*qu)->name_room->right;
	while (tmp)
	{
		if (tmp->name_room->color != GRAY)
		{
			tmp = tmp->next;
			continue ;
		}
		if (tmp)
		{
			(*q_l)->next = (t_links*)malloc(sizeof(t_links));
			(*q_l) = (*q_l)->next;
		}
		(*q_l)->name_room = tmp->name_room;
		(*q_l)->name_room->color = WHITE;
		(*q_l)->name_room->weight = (*qu)->name_room->weight + 1;
		tmp = tmp->next;
	}
	(*q_l)->next = NULL;
	(*qu)->name_room->color = BLACK;
	tmp = (*qu);
	(*qu) = (*qu)->next;
	(tmp) ? free(tmp) : 0;
}

t_links				*ft_queue_crt(t_able *start)
{
	t_links			*queue;

	queue = (t_links*)malloc(sizeof(t_links));
	while (start && (start->n != START))
		start = start->next;
	queue->name_room = start;
	queue->door = CLOSE;
	queue->next = NULL;
	queue->count_ants = 0;
	queue->prev = NULL;
	return (queue);
}

static void			ft_go_home_ants(t_lem *in, t_able *min_w, t_links *help)
{
	t_links			*queue;
	t_links			*queue_last;

	queue = ft_queue_crt(in->adj_matrix);
	queue_last = queue;
	while (queue_last->name_room->n != END)
	{
		min_w = queue_last->name_room->right->name_room;
		help = queue_last->name_room->right;
		while (help)
		{
			if (min_w->weight > help->name_room->weight)
				min_w = help->name_room;
			help = help->next;
		}
		queue_last->next = (t_links*)malloc(sizeof(t_links));
		queue_last->next->prev = queue_last;
		queue_last = queue_last->next;
		queue_last->door = CLOSE;
		queue_last->count_ants = 0;
		queue_last->next = NULL;
		queue_last->name_room = min_w;
	}
	ft_close_doors(queue, in);
}

void				ft_queue(t_lem *in)
{
	t_able			*end;
	t_links			*queue;
	t_links			*queue_last;
	int				i;

	i = 0;
	end = in->adj_matrix;
	while (end && (end->n != END))
		end = end->next;
	queue = (t_links*)malloc(sizeof(t_links));
	queue->name_room = end;
	queue->name_room->color = WHITE;
	queue->next = NULL;
	queue_last = queue;
	while (i++ < in->num_rooms)
		crt_q(&queue, &queue_last, in, NULL);
	ft_go_home_ants(in, NULL, NULL);
	ft_other_ways(in);
}
