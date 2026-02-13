/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:47:06 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/13 15:47:07 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

void	ft_free(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*temp;

	if (list == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node->str[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_nl(t_list *list)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				++len;
				return (len);
			}
			++len;
			++i;
		}
		list = list->next;
	}
	return (len);
}

int	found_newline(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	append_to_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str = buf;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
