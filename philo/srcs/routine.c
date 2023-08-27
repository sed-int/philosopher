/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:36 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/27 15:16:37 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_env *env, t_philo *philo)
{
	pthread_mutex_lock(&env->mutex[philo->left]);
	print_msg(philo, "has taken a fork");
	if (env->is_over)
	{
		pthread_mutex_unlock(&env->mutex[philo->left]);
		return ;
	}
	pthread_mutex_lock(&env->mutex[philo->right]);
	print_msg(philo, "has taken a fork");
	if (env->is_over)
	{
		pthread_mutex_unlock(&env->mutex[philo->right]);
		pthread_mutex_unlock(&env->mutex[philo->left]);
		return ;
	}
}

void	eat_meal(t_env *env, t_philo *philo)
{
	if (env->is_over)
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
	// if (is_dead(philo, env))
	// {
	// 	pthread_mutex_lock(&env->over_mutex);
	// 	if (!env->is_over)
	// 		philo->is_dead = 1;
	// 	pthread_mutex_unlock(&env->over_mutex);
	// 	return ;
	// }
	if (env->is_over)
		return ;
	print_msg(philo, "is sleeping");
	ft_usleep(env->arg.time_to_sleep);
}

void	think_philo(t_env *env, t_philo *philo)
{
	// if (is_dead(philo, env))
	// {
	// 	pthread_mutex_lock(&env->over_mutex);
	// 	if (!env->is_over)
	// 		philo->is_dead = 1;
	// 	pthread_mutex_unlock(&env->over_mutex);
	// 	return ;
	// }
	if (env->is_over)
		return ;
	print_msg(philo, "is thinking");
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->env->over_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->env->over_mutex);
	if (philo->num % 2 == 0)
		ft_usleep(philo->env->arg.time_to_sleep);
	while (!philo->env->is_over)
	{
		pick_forks(philo->env, philo);
		eat_meal(philo->env, philo);
		sleep_philo(philo->env, philo);
		think_philo(philo->env, philo);
	}
	return (0);
}
