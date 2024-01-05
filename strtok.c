/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/05 01:37:41 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*my_strtok(char *src, char *delim)
{
	static char	*backup;
	char		*ret;

	(!src) && (src = backup);
	if (!src)
		return (NULL);
	while (1)
	{
		while (is_delim(*src, delim))
			src++;
		if (*src == '\0')
			return (NULL);
		break ;
	}
	ret = src;
	while (1)
	{
		if (*src == '\0')
			return (backup = src, ret);
		if (is_delim(*src, delim))
			return (*src = '\0', backup = src + 1, ret);
		src++;
	}
}
