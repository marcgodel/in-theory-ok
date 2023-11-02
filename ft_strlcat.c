/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:37:40 by mgodel            #+#    #+#             */
/*   Updated: 2023/11/02 10:30:42 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	len_dst;
	unsigned long	len_src;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	len_dst = 0;
	len_src = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (dstsize < len_dst)
		return (dstsize + len_src);
	else
	{
		while (i < (dstsize - 1) && src[j] && dstsize != 0)
			dst[i++] = (char)src[j++];
		dst[i] = 0;
	}
	return (len_dst + len_src);
}
