/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:17 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/13 12:16:15 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_out(char *out_free)
{
	if (out_free != NULL)
	{
		free(out_free);
		out_free = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*out;
	char		*buf;
	ssize_t		readen;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147479552 || read(fd, 0, 0) == -1)
		return (free_out(out), NULL);
	if (have_n(out))
		return (print_line(&out));
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	readen = 1;
	while (readen > 0)
	{
		readen = read(fd, buf, BUFFER_SIZE);
		buf[readen] = 0;
		out = ft_strjoin(out, buf);
		if (have_n(out))
			break ;
	}
	if (buf)
		free(buf);
	buf = NULL;
	return (print_line(&out));
}
