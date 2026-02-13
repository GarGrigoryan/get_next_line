/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:46:54 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/13 15:54:22 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

static t_list	*get_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static void	clear_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	clean_node = (t_list *)malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = get_last_node(*list);
	while (last_node->str[i] != '\0' && last_node->str[i] != '\n')
		++i;
	while (last_node->str[i] != '\0' && last_node->str[++i])
		buf[j++] = last_node->str[i];
	buf[j] = '\0';
	clean_node->str = buf;
	clean_node->next = NULL;
	ft_free(list, clean_node, buf);
}

static char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_nl(list);
	next_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

static void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	char_read = 0;
	while (!found_newline(*list))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append_to_list(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0 || fd > 4095)
		return (NULL);
	create_list(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	next_line = get_line(list[fd]);
	clear_list(&list[fd]);
	return (next_line);
}

/*
int main(void)
{
	int fd = open("text.txt", O_RDONLY);
    char *line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
*/
