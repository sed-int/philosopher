/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:36 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/24 10:34:39 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_env *env, t_philo *philo)
{
	pthread_mutex_lock(&env->mutex[philo->left]);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&env->mutex[philo->right]);
	if (is_dead(philo, env))
	{
		pthread_mutex_lock(&env->dead_mutex);
		if (env->is_dead == -1)
			env->is_dead = philo->num;
		pthread_mutex_unlock(&env->dead_mutex);
		pthread_mutex_unlock(&env->mutex[philo->right]);
		pthread_mutex_unlock(&env->mutex[philo->left]);
		return ;
	}
	print_msg(philo, "has taken a fork");
}

void	eat_meal(t_env *env, t_philo *philo)
{
	philo->last_eat_time = get_time();
	print_msg(philo, "is eating");
	philo->eat_cnt++;
	ft_usleep(env->arg.time_to_eat);
	pthread_mutex_unlock(&env->mutex[philo->right]);
	pthread_mutex_unlock(&env->mutex[philo->left]);
}

void	sleep_philo(t_env *env, t_philo *philo)
{
	if (is_dead(philo, env))
	{
		pthread_mutex_lock(&env->dead_mutex);
		if (env->is_dead == -1)
			env->is_dead = philo->num;
		pthread_mutex_unlock(&env->dead_mutex);
		return ;
	}
	print_msg(philo, "is sleeping");
	ft_usleep(env->arg.time_to_sleep);
}

void	think_philo(t_env *env, t_philo *philo)
{
	if (is_dead(philo, env))
	{
		pthread_mutex_lock(&env->dead_mutex);
		if (env->is_dead == -1)
			env->is_dead = philo->num;
		pthread_mutex_unlock(&env->dead_mutex);
		return ;
	}
	print_msg(philo, "is thinking");
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->last_eat_time = get_time();
	if (philo->num % 2)
		ft_usleep(philo->env->arg.time_to_sleep);
	while (philo->env->is_dead == -1)
	{
		pick_forks(philo->env, philo);
		eat_meal(philo->env, philo);
		sleep_philo(philo->env, philo);
		think_philo(philo->env, philo);
	}
	if (philo->num == philo->env->is_dead)
		printf("%ld %d died\n", get_time() - philo->env->start_time, philo->num);
	return (0);
}
