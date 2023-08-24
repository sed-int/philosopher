/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:50:04 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/24 10:07:03 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_env *env, t_philo *philo)
{
	int	current;

	current = get_time();
	if (current - philo->last_eat_time > env->arg.time_to_die)
		env->is_dead = philo->num;
}

long	get_time(void)
{
	t_time	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
	return (1);
}

int	is_dead(t_philo *philo, t_env *env)
{
	return (get_time() - philo->last_eat_time > env->arg.time_to_die);
}
