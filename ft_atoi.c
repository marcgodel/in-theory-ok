/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:06:11 by mgodel            #+#    #+#             */
/*   Updated: 2023/10/25 17:25:36 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace_atoi(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_isnegative_atoi(char c)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	temp;
	int	number;
	int	is_negative;

	temp = 0;
	number = 0;
	i = 0;
	is_negative = 0;
	while (ft_isspace_atoi(str[i]))
			i++;
	if (str[i] == '-' || str[i] == '+')
		is_negative = ft_isnegative_atoi(str[i++]);
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (number);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{		
		temp = str[i] - 48;
		number = (number * 10) + temp;
		i++;
	}
	if (is_negative)
		return (number = number * -1);
	return (number);
}
