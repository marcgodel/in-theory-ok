/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:09:54 by mgodel            #+#    #+#             */
/*   Updated: 2023/11/01 16:34:59 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned long	find_start(char const *s, const char *set)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	while (s[i])
	{
		while (s[i])
		{
			j = 0;
			while (s[i] == set[j] && s[i])
				i++;
			if (s[i] == 0)
				return (0);
			while (s[i] != set[j])
			{
				if (set[j] == 0)
					return (i);
				j++;
			}
			i++;
		}
	}
	return (0);
}

static unsigned long	find_end(char const *s, char const *set, size_t i)
{
	unsigned long	j;

	while (i != 0)
	{
		j = 0;
		while (i != 0 && set[j] == s[i])
			i--;
		if (i == 0)
			return (0);
		while (set[j] != s[i])
		{
			if (set[j] == 0)
				return (i + 1);
			j++;
		}
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	start;
	unsigned long	end;
	unsigned long	i;
	char			*str;

	start = 0;
	end = 0;
	start = find_start(s1, set);
	i = start;
	while (s1[i])
		i++;
	if (i != 0)
		i--;
	end = find_end(s1, set, i);
	str = malloc(sizeof(char) * ((end - start) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = (char)s1[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
0123456789
ppppppppppaa */
