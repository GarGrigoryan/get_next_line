/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargrigo <gargrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:58:05 by gargrigo          #+#    #+#             */
/*   Updated: 2026/02/10 17:11:59 by gargrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*str;
	
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (NULL);
}

int	main(void)
{
	get_next_line(3);
	return (0);
}
