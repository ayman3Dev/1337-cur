/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaraba <aaaraba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:00:34 by aaaraba           #+#    #+#             */
/*   Updated: 2024/01/21 12:00:35 by aaaraba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cheaknewline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*readfromfile(int fd, char *buffer, char *new)
{
	char	*freenew;
	int		c;

	c = 1;
	while (c > 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c == 0 && new == 0)
			return (free(buffer), buffer = NULL, NULL);
		if (c <= 0)
			break ;
		buffer[c] = '\0';
		freenew = new;
		new = ft_strjoin(new, buffer);
		if (new == NULL)
			return (free (freenew), free(buffer), NULL);
		free(freenew);
		if (ft_cheaknewline(buffer) != NULL)
			break ;
	}
	free(buffer);
	return (new);
}

char	*copy_in_newstr(char *new, char *s, int *o)
{
	int	i;

	i = 0;
	while (new[i] != '\n' && new[i])
		i++;
	if (new[i] == '\n')
		i++;
	s = ft_substr(new, 0, i);
	if (s == NULL)
		return (NULL);
	*o = i;
	return (s);
}

char	*check_free_new(char *new)
{
	if (new[0] == 0)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*new[10240];
	char		*s;
	char		*buffer;
	char		*temp;
	int			x;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, "", 0) < 0)
		return (free(new[fd]), new[fd] = 0, NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buffer == NULL)
		return (free(new[fd]), new[fd] = NULL, NULL);
	new[fd] = readfromfile(fd, buffer, new[fd]);
	if (new[fd] == NULL)
		return (NULL);
	x = 0;
	s = copy_in_newstr(new[fd], NULL, &x);
	if (s == NULL)
		return (free(new[fd]), new[fd] = 0, NULL);
	temp = new[fd];
	new[fd] = ft_strdup(new[fd] + x);
	if (new[fd] == NULL)
		return (free(s), free(temp), NULL);
	free(temp);
	new[fd] = check_free_new(new[fd]);
	return (s);
}
