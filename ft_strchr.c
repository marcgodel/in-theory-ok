/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:55:01 by mgodel            #+#    #+#             */
/*   Updated: 2023/11/01 16:29:58 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char) c;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == ch)
		return (&((char *)s)[i]);
	else
		return (NULL);
}		
