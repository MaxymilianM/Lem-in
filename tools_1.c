/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:28:32 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/27 11:28:36 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_clean_bad_queue(t_links *queue)
{
	t_links			*dell;

	while (queue)
	{
		dell = queue;
		queue = queue->next;
		free(dell);
	}
}

t_list				*ft_find_first_room(t_lem *in)
{
	t_list			*help;
	char			*str;

	help = in->head_t;
	while (help)
	{
		str = help->content;
		if (str[0] == '#' && str[1] != '#')
			help = help->next;
		else
			break ;
	}
	if (help)
	{
		str = help->content;
		if (str[1] != '#')
			help = help->next;
	}
	return (help);
}

void				ft_dell_room(t_able **head, t_able *current, t_lem *in)
{
	t_able			*tmp;

	tmp = *head;
	in->num_rooms--;
	if (current->n == START || current->n == END)
		ft_error_exit(in, 3);
	if (tmp == current)
		*head = current->next;
	else if (tmp->next == current)
		(*head)->next = current->next;
	else
	{
		while (tmp->next != current)
			tmp = tmp->next;
		tmp->next = current->next;
	}
	free(current->name);
	free(current);
}

void				ft_close_end(t_lem *in)
{
	t_links			*end;
	t_ways			*allw;

	allw = in->all_ways;
	while (allw)
	{
		end = allw->way;
		while (end && (end->name_room->n != END))
		{
			allw->sum++;
			end = end->next;
		}
		end->name_room->door = CLOSE;
		allw = allw->next;
	}
}

void				ft_print_all_text(t_lem *in)
{
	t_list			*print;

	print = in->head_t;
	while (print)
	{
		ft_printf("%s\n", print->content);
		print = print->next;
	}
	ft_printf("\n");
}
