/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:25:41 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/23 02:17:24 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_stash;

	while (!*stash || !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
			return (0);
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(*stash, buffer);
		if (!new_stash)
			return (*stash = NULL, -1);
		*stash = new_stash;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			read_results;
	char		*line;
	char		*new_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_results = read_stash(fd, &stash);
	if (read_results == -1 || !stash || !stash[0])
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	new_stash = ft_update_stash(stash);
	free(stash);
	stash = new_stash;
	return (line);
}
