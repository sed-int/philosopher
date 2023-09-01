/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:42:08 by hcho2             #+#    #+#             */
/*   Updated: 2023/09/01 13:33:04 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_env *env)
{
	free(env->philos);
	free(env->forks);
	free(env->mutex);
	free(env);
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
	if (str[i])
		return (-1);
	return (sign * ret);
}
