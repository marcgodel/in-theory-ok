/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:50:02 by mgodel            #+#    #+#             */
/*   Updated: 2023/10/31 19:01:35 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			*dst_t;
	char			*src_t;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_t = (char *)dst;
	src_t = (char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			dst_t[i] = src_t[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dst_t[len] = src_t[len];
	}
	return (dst);
}
