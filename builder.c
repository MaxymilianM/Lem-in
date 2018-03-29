/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:46:03 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/13 19:46:06 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_able			*ft_new_table(char *str, t_lem *in, int i, t_able *new_node)
{
	new_node = (t_able*)malloc(sizeof(t_able));
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	if (str[i] == '\0' || new_node == NULL)
		return (NULL);
	new_node->n = 2;
	if (in->start == 1)
	{
		new_node->n = START;
		in->start = 0;
	}
	else if (in->end == 1)
	{
		new_node->n = END;
		in->end = 0;
	}
	new_node->weight = 0;
	new_node->door = OPEN;
	new_node->count_ants = 0;
	new_node->color = GRAY;
	new_node->name = ft_strsub(str, 0, i);
	new_node->next = NULL;
	new_node->right = NULL;
	return (new_node);
}

int				ft_find_room(char *s, t_lem *in)
{
	if (s[0] == '#')
	{
		if (s[1] == '#')
		{
			(ft_strequ(s, "##start")) ? (in->start = 1) : 0;
			(ft_strequ(s, "##end")) ? (in->end = 1) : 0;
		}
		return (0);
	}
	else if (ft_strchr(s, '-'))
		return (0);
	return (1);
}

void			ft_clean(char **str)
{
	int			i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int				ft_find_links(char *s)
{
	if (s[0] != '#')
	{
		if (ft_strchr(s, '-'))
			return (1);
	}
	return (0);
}

void			ft_builder(t_lem *in)
{
	t_able		*adj_matrix;
	t_list		*help;

	adj_matrix = NULL;
	help = ft_find_first_room(in);
	while (help)
	{
		if (ft_find_room(help->content, in) == 1)
		{
			if (adj_matrix == NULL)
			{
				adj_matrix = ft_new_table(help->content, in, 0, NULL);
				in->adj_matrix = adj_matrix;
			}
			else
			{
				adj_matrix->next = ft_new_table(help->content, in, 0, NULL);
				adj_matrix = adj_matrix->next;
			}
			(adj_matrix == NULL) ? ft_error_exit(in, 1) : 0;
			in->num_rooms++;
		}
		help = help->next;
	}
	ft_finish_build(in);
}
