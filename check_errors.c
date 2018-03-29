/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:40:43 by mminenko          #+#    #+#             */
/*   Updated: 2018/03/27 11:40:45 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_ck_room_names(t_lem *in, t_list *list)
{
	char		*str;
	char		*ptr;
	int			spaces;

	spaces = 0;
	while (list)
	{
		str = list->content;
		if (ft_strchr(str, '-'))
			;
		else if ((ptr = ft_strchr(str, ' ')) != NULL && str[0] != '#')
		{
			spaces = 0;
			while (*ptr)
			{
				if (*ptr == ' ')
					spaces++;
				else if (!ft_isdigit(*ptr))
					ft_error_exit(in, 1);
				ptr++;
			}
			(spaces != 2) ? ft_error_exit(in, 1) : 0;
		}
		list = list->next;
	}
}

void			ft_ck_end(t_lem *in, t_list *list)
{
	int			find_e;
	char		*str;

	find_e = 0;
	while (list)
	{
		str = list->content;
		if (str[0] == '#' && str[1] == '#')
		{
			if (ft_strequ(str, "##end"))
				find_e = 1;
		}
		else if (find_e == 1 && str[0] != '#')
		{
			if (ft_strchr(str, '-') || ft_strequ(str, "##start"))
				ft_error_exit(in, 10);
			else
				break ;
		}
		list = list->next;
	}
}

void			ft_ck_start(t_lem *in, t_list *list)
{
	int			find_s;
	char		*str;

	find_s = 0;
	while (list)
	{
		str = list->content;
		if (str[0] == '#' && str[1] == '#')
		{
			if (ft_strequ(str, "##start"))
				find_s = 1;
		}
		else if (find_s == 1 && str[0] != '#')
		{
			if (ft_strchr(str, '-') || ft_strequ(str, "##end"))
				ft_error_exit(in, 10);
			else
				break ;
		}
		list = list->next;
	}
}

void			ft_ck_links(t_lem *in, t_list *list)
{
	int			find;
	char		*str;

	find = 0;
	while (list)
	{
		str = list->content;
		if (str[0] == '#')
		{
			if (str[1] == '#')
			{
				if ((ft_strequ(str, "##start") ||
					ft_strequ(str, "##end")) && find == 1)
					ft_error_exit(in, 11);
			}
		}
		else if (find == 1)
		{
			if (!(ft_strchr(str, '-')))
				ft_error_exit(in, 9);
		}
		else if (ft_strchr(str, '-'))
			find = 1;
		list = list->next;
	}
}
