/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:36 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/20 20:49:42 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_env *env, t_philo philo)
{
}

void	eat_meal(t_env *env, t_philo philo)
{
	pthread_mutex_unlock(&env->mutex[philo.num]);
	pthread_mutex_unlock(&env->mutex[philo.num + 1]);
}

void	sleep_philo(t_env *env, t_philo philo)
{
}

void	think_philo(t_env *env, t_philo philo)
{
}

void	routine(void *env)
{
	pick_forks();
	eat_meal();
	sleep_philo();
	think_philo();
}
