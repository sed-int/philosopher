/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:16:16 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/25 18:18:30 by hcho2            ###   ########.fr       */
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
		if (env->eat_cnt == env->arg.number_of_philos || env->is_dead != -1)
			env->is_over = 1;
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
		env->eat_cnt = 0;
		while (i < env->arg.number_of_philos)
		{
			if (env->philos[i].is_dead)
				env->is_over = 1;
			i++;
		}
	}
	return (NULL);
}
