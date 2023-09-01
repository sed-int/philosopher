/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:50:04 by hcho2             #+#    #+#             */
/*   Updated: 2023/09/01 13:44:46 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	is_over(t_env *env)
{
	pthread_mutex_lock(&env->over_mutex);
	if (env->is_over)
	{
		pthread_mutex_unlock(&env->over_mutex);
		return (1);
	}
	pthread_mutex_unlock(&env->over_mutex);
	return (0);
}

void	print_msg(t_philo *philo, char *msg)
{
	long	current;

	pthread_mutex_lock(&philo->env->over_mutex);
	current = get_time() - philo->env->start_time;
	if (!philo->env->is_over)
		printf("%ld %d %s\n", current, philo->num, msg);
	pthread_mutex_unlock(&philo->env->over_mutex);
}
