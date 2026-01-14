/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-f <agomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:23:19 by agomes-f          #+#    #+#             */
/*   Updated: 2026/01/09 19:13:29 by agomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    const char *start;
    
    start = s;
    while (*s++)
        ;
    return (s - start);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;
    
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    while (!dst && !src)
        return (NULL);
    while (n--)
        *d++ = *s++;
    return (dst);
}

void *ft_strdup(const char *str)
{
    size_t len;
    char *dst;
    
    len = ft_strlen(str) + 1;
    dst = (char *)malloc(len * sizeof(char));
    if (!dst)
        return (NULL);
    ft_memcpy(dst, str, len);
    return (dst);
}

void *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;
    
    i = 0;
    substr = malloc((len + 1) * sizeof(char));
    if (!substr)
        return (NULL);
    while (i < len && *(s + start + i))
    {
        *(substr + i) = *(s + start + i);
        i++;
    }
    *(substr + i) = '\0';
    return (substr);
}