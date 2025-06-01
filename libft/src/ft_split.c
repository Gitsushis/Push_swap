/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:11:46 by cbouyer           #+#    #+#             */
/*   Updated: 2025/05/27 23:13:50 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_count(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	*ft_strndup(const char *str, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_next(const char *str, char c, int *pos)
{
	int	start;
	int	len;

	start = *pos;
	len = 0;
	while (str[start] == c)
		start++;
	while (str[start + len] && str[start + len] != c)
		len++;
	*pos = start + len;
	return (ft_strndup(str, start, len));
}

/**
 * Ceci est ma fonction split
 */
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		count;
	int		pos;
	int		i;

	pos = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = ft_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	while (i < count)
	{
		strs[i] = ft_next(s, c, &pos);
		if (!strs[i])
		{
			ft_freemem(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
