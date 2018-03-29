/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:34:22 by mminenko          #+#    #+#             */
/*   Updated: 2017/12/13 16:34:23 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*reader(const int fd, t_urtle *raphael, char *readed)
{
	char				buf[BUFF_SIZE + 1];
	char				*tmp;
	ssize_t				ret;

	tmp = ft_strnew(BUFF_SIZE);
	if (raphael != NULL && raphael->content != NULL)
	{
		free(tmp);
		tmp = raphael->content;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		readed = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
		tmp = readed;
	}
	if (readed == NULL && !(raphael != NULL && raphael->content != NULL))
		free(tmp);
	if (readed == NULL)
		readed = raphael->content;
	return (readed);
}

static t_urtle			*new_ninja(const int fd, char *str, char ***lines)
{
	t_urtle				*michelangelo;

	if ((michelangelo = (t_urtle *)malloc(sizeof(t_urtle))) == NULL)
		return (NULL);
	if (lines)
		free(*lines);
	michelangelo->content = str;
	michelangelo->fd = fd;
	michelangelo->next = NULL;
	return (michelangelo);
}

static char				**line_delimeter(char *two_str)
{
	ssize_t				i;
	char				**lines;

	lines = (char **)malloc(sizeof(char *) * 2);
	i = 0;
	lines[1] = NULL;
	while (two_str[i] != '\n' && two_str[i] != '\0')
		i++;
	lines[0] = ft_strnew(i);
	i = 0;
	while (two_str[i] != '\n' && two_str[i] != '\0')
	{
		lines[0][i] = two_str[i];
		i++;
	}
	if (two_str[i] == '\n')
		i++;
	if (two_str[i] != '\0')
		lines[1] = ft_strsub(two_str, i, ft_strlen(two_str));
	free(two_str);
	return (lines);
}

static t_urtle			*find_list(t_urtle *raphael, const int fd)
{
	t_urtle				*leonardo;

	if (raphael->fd == fd)
		return (raphael);
	while (raphael->next != NULL)
	{
		raphael = raphael->next;
		if (raphael->fd == fd)
			return (raphael);
	}
	if (raphael->fd == fd)
		return (raphael);
	leonardo = new_ninja(fd, NULL, NULL);
	raphael->next = leonardo;
	return (leonardo);
}

int						get_next_line(const int fd, char **line)
{
	static	t_urtle		*raphael;
	char				*two_str;
	char				**lines;
	t_urtle				*donatello;

	if (fd < 0 || line == NULL || (read(fd, NULL, 0)) == -1 || BUFF_SIZE <= 0)
		return (-1);
	donatello = raphael;
	if (raphael == NULL && (lines = line_delimeter(reader(fd, raphael, NULL))))
	{
		*line = lines[0];
		raphael = new_ninja(fd, lines[1], &lines);
	}
	else if ((donatello = find_list(donatello, fd)) != NULL)
	{
		if ((two_str = reader(fd, donatello, NULL)) == NULL)
			return (0);
		else if ((lines = line_delimeter(two_str)) != NULL)
		{
			*line = lines[0];
			donatello->content = lines[1];
			free(lines);
		}
	}
	return (1);
}
