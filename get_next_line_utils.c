/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:09:53 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/23 02:05:26 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strchr(char *str, int character)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)character)
			return (str);
		str++;
	}
	if (character == '\0')
		return (str);
	return (NULL);
}
// This function will join two strings into one single string, but the thing is,
// it won't concatenate them as you think.
// Instead, it will start overwriting the second string at 
// the end of the first string, like this:
// str1 had = "Hello world     "
// str2 had = "shit world"
// the finall result will be:
// res = "Hello shit world"

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	length_1;
	size_t	length_2;
	size_t	index;
	char	*result;

	length_1 = ft_strlen(str1);
	length_2 = ft_strlen(str2);
	result = malloc(length_1 + length_2 + 1);
	if (!result)
		return (free(str1), NULL);
	index = 0;
	while (index < length_1)
	{
		result[index] = str1[index];
		index++;
	}
	while (index < length_1 + length_2)
	{
		result[index] = str2[index - length_1];
		index++;
	}
	result[index] = '\0';
	free(str1);
	return (result);
}

char	*ft_extract_line(char *stash)
{
	size_t	index;
	size_t	length;
	char	*line;

	length = 0;
	while (stash[length] && stash[length] != '\n')
		length++;
	if (stash[length] == '\n')
		length++;
	line = malloc(length + 1);
	if (!line)
		return (NULL);
	index = 0;
	while (index < length)
	{
		line[index] = stash[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_update_stash(char *stash)
{
	size_t	index;
	size_t	start;
	size_t	length;
	char	*new_stash;

	index = 0;
	while (stash[index] && stash[index] != '\n')
		index++;
	if (!stash[index])
		return (NULL);
	start = index + 1;
	length = ft_strlen(stash + start);
	new_stash = malloc (length + 1);
	if (!new_stash)
		return (NULL);
	index = 0;
	while (index < length)
	{
		new_stash[index] = stash[start + index];
		index++;
	}
	new_stash[index] = '\0';
	return (new_stash);
}
