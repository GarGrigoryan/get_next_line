/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:02:34 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/19 18:44:20 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

void	free_list(t_list **list);
char	*get_next_line(int fd);
void	ft_free(t_list **list, t_list *clean_node, char *buf);
int		len_to_nl(t_list *list);
void	copy_str(t_list *list, char *str);
int		found_newline(t_list *list);
void	append_to_list(t_list **list, char *buf);

#endif
