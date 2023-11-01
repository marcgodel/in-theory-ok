/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:19:08 by mgodel            #+#    #+#             */
/*   Updated: 2023/11/01 16:29:26 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned long	count_word(const char *s, char c)
{
	unsigned long	i;
	unsigned long	nb_word;

	i = 0;
	nb_word = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		nb_word++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_word);
}

static unsigned long	len_word(const char *s, char c)
{
	unsigned long	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	put_str(char *dest, const char *str, unsigned long len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
	{
		dest[i] = (char)str[i];
		i++;
	}
	dest[i] = 0;
}

static int	fill_words(char **tab, size_t nb_word, const char *s, char c)
{
	unsigned long	num;
	unsigned long	i;
	unsigned long	len;

	num = 0;
	i = 0;
	while (num < nb_word)
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		len = len_word(&s[i], c);
		tab[num] = malloc(sizeof(char) * (len + 1));
		if (tab[num] == NULL)
			return (0);
		put_str(tab[num], &s[i], len);
		i = i + len;
		num++;
	}
	tab[num] = (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned long	nb_word;
	int				i;

	nb_word = 0;
	i = 0;
	nb_word = count_word(s, c);
	tab = malloc(sizeof(char *) * (nb_word + 1));
	if (tab == NULL)
	{
		free (tab);
		return (NULL);
	}
	i = fill_words(tab, nb_word, s, c);
	if (i == 0)
	{
		while (tab[i])
			free (tab[i++]);
		free (tab);
		return (NULL);
	}
	return (tab);
}
