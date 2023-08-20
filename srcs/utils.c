/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:42:08 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/20 12:53:01 by hcho2            ###   ########.fr       */
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
