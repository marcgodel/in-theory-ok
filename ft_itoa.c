/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:42:05 by mgodel            #+#    #+#             */
/*   Updated: 2023/11/01 16:37:41 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_length_itoa(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	ft_fill_str(char *s, int i, int n)
{	
	if (n < 0)
	{
		while (n < 0)
		{
			s[i] = '0' + ((n % 10) * (-1));
			n = n / 10;
			i--;
		}
		s[i] = '-';
	}
	else
	{
		while (i >= 0)
		{
			s[i] = '0' + (n % 10);
			n = n / 10;
			i--;
		}
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	i = ft_length_itoa(n);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	ft_fill_str(str, i, n);
	return (str);
}
