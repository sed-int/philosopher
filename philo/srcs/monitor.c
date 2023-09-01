/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:16:16 by hcho2             #+#    #+#             */
/*   Updated: 2023/09/01 13:47:09 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*count_monitor(void *arg)
{
	t_env	*env;
	int		i;

	env = arg;
	while (!env->is_over)
	{
		i = 0;
		env->eat_cnt = 0;
		while (i < env->arg.number_of_philos)
		{
			if (env->philos[i].eat_cnt >= env->arg.must_eat_count)
				env->eat_cnt++;
			i++;
		}
		pthread_mutex_lock(&env->over_mutex);
		if (env->eat_cnt == env->arg.number_of_philos)
			env->is_over = OVER;
		pthread_mutex_unlock(&env->over_mutex);
	}
	return (NULL);
}

void	*death_monitor(void *arg)
{
	t_env	*env;
	int		i;

	env = arg;
	while (!env->is_over)
	{
		i = 0;
		while (i < env->arg.number_of_philos)
		{
			pthread_mutex_lock(&env->over_mutex);
			if (is_dead(&env->philos[i], env))
			{
				printf("%ld %d died\n", get_time() - env->start_time, i + 1);
				env->is_over = DEAD;
				pthread_mutex_unlock(&env->mutex[env->philos[i].right]);
				pthread_mutex_unlock(&env->mutex[env->philos[i].left]);
				pthread_mutex_unlock(&env->over_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&env->over_mutex);
			i++;
		}
	}
	return (NULL);
}
