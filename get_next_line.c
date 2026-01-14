/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-f <agomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:23:17 by agomes-f          #+#    #+#             */
/*   Updated: 2026/01/09 20:09:24 by agomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *process_line(char **stash)
{
    char *line;
    char *leftovers;
    int len;
    
    len = 0;
    while ((*stash[len] != '\n') && (*stash[len] != '\0'))
        len++;
    if ((*stash[len] == '\n'))
    {
        line = ft_substr(*stash, 0, len + 1);
        leftovers = ft_substr(*stash, len + 1, ft_strlen(*stash) (len + 1));
        free(*stash);
        *stash = leftovers;
        return (line);
    }
    return (NULL);
}



char *get_next_line(int fd)
{
    
}