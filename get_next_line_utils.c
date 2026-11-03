/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suobeida <suobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:55:32 by suobeida          #+#    #+#             */
/*   Updated: 2026/10/25 17:57:17 by suobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_free(char *stash, const char *buf)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(stash);
	len2 = ft_strlen(buf);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (free(stash), NULL);
	ft_memcpy(res, stash, len1);
	ft_memcpy(res + len1, buf, len2);
	res[len1 + len2] = '\0';
	free(stash);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_init_stash(char **stash)
{
	if (*stash)
		return (1);
	*stash = malloc(1);
	if (!*stash)
		return (0);
	(*stash)[0] = '\0';
	return (1);
}
