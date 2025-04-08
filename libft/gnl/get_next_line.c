/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:48:42 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/12 17:48:45 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*extract_line(char **stack)
{
	char	*line;
	char	*new_stack;
	size_t	len;

	len = 0;
	while ((*stack)[len] && (*stack)[len] != '\n')
		len++;
	if ((*stack)[len] == '\n')
	{
		line = ft_substr(*stack, 0, len + 1);
		new_stack = ft_strdup(*stack + len + 1);
	}
	else
	{
		line = ft_strdup(*stack);
		new_stack = NULL;
	}
	free(*stack);
	*stack = new_stack;
	return (line);
}

char	*read_fd(int fd, char **stack)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(*stack, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(*stack);
			free(buffer);
			stack = NULL;
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(*stack, buffer);
		free(*stack);
		*stack = temp;
	}
	free(buffer);
	return (*stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stack[fd])
		stack[fd] = ft_strdup("");
	stack[fd] = read_fd(fd, &stack[fd]);
	if (!stack[fd] || *stack[fd] == '\0')
	{
		free(stack[fd]);
		stack[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&stack[fd]));
}
