/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:57:19 by mgodel            #+#    #+#             */
/*   Updated: 2023/11/01 16:35:58 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	len_of_malloc(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	unsigned long	len_s;

	i = (unsigned long) start;
	len_s = 0;
	while (s[len_s])
		len_s++;
	if (i >= len_s)
		return (0);
	if (len >= len_s)
		return (len_s - i);
	if (len_s - i >= len)
		return (len);
	if (len_s - i < len)
		return (len_s - i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	i = len_of_malloc(s, start, len);
	new_str = malloc(sizeof(char) * (i + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			new_str[j] = s[i];
			j++;
		}
		i++;
	}
	new_str[j] = 0;
	return (new_str);
}
