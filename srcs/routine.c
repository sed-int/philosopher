/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:36 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/25 15:12:30 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_env *env, t_philo *philo)
{
	pthread_mutex_lock(&env->mutex[philo->left]);
	print_msg(philo, "has taken a fork");
	if (is_dead(philo, env) || env->arg.number_of_philos == 1)
	{
		pthread_mutex_lock(&env->dead_mutex);
		if (env->is_dead == -1)
			env->is_dead = philo->num;
		pthread_mutex_unlock(&env->dead_mutex);
		pthread_mutex_unlock(&env->mutex[philo->left]);
		return ;
	}
	pthread_mutex_lock(&env->mutex[philo->right]);
	print_msg(philo, "has taken a fork");
	if (is_dead(philo, env) || env->is_dead != -1)
	{
		pthread_mutex_lock(&env->dead_mutex);
		if (env->is_dead == -1)
			env->is_dead = philo->num;
		pthread_mutex_unlock(&env->dead_mutex);
		pthread_mutex_unlock(&env->mutex[philo->right]);
		pthread_mutex_unlock(&env->mutex[philo->left]);
		return ;
	}
}

void	eat_meal(t_env *env, t_philo *philo)
{
	if (env->is_dead != -1)
		return ;
	philo->last_eat_time = get_time();
	print_msg(philo, "is eating");
	philo->eat_cnt++;
	ft_usleep(env->arg.time_to_eat);
	pthread_mutex_unlock(&env->mutex[philo->right]);
	pthread_mutex_unlock(&env->mutex[philo->left]);
}

void	sleep_philo(t_env *env, t_philo *philo)
{
	if (is_dead(philo, env) || env->is_dead != -1)
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
	if (is_dead(philo, env) || env->is_dead != -1)
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
	long	current;

	philo = (t_philo *)data;
	philo->last_eat_time = get_time();
	if (philo->num % 2 == 0)
		ft_usleep(philo->env->arg.time_to_sleep);
	while (!philo->env->is_over)
	{
		pick_forks(philo->env, philo);
		eat_meal(philo->env, philo);
		sleep_philo(philo->env, philo);
		think_philo(philo->env, philo);
	}
	current = get_time() - philo->env->start_time;
	if (philo->num == philo->env->is_dead)
		printf("%ld %d died\n", current, philo->num);
	return (0);
}
