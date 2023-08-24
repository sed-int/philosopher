/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:42:08 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/24 10:32:54 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->arg.number_of_philos)
	{
		free(&env->philos[i]);
		free(&env->forks[i]);
		free(&env->mutex[i]);
		i++;
	}
}

void	print_msg(t_philo *philo, char *msg)
{
	long	current;

	current = get_time() - philo->env->start_time;
	if (philo->env->is_dead == -1)
		printf("%ld %d %s\n", current, philo->num, msg);
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
