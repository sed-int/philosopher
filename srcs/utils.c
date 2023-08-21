/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:42:08 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 20:59:21 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	numlen(long long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ret;
	size_t		len;
	long long	nb;

	nb = (long long)n;
	len = numlen(nb);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len--] = '\0';
	if (nb == 0)
		ret[0] = '0';
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		ret[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	return (sign * ret);
}
