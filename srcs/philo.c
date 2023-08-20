/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:19:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/18 17:02:01 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	init_arg(char **av)
{
	t_arg	arg;

	arg.number_of_philo = ft_atoi(av[1]);
	arg.time_to_die = ft_atoi(av[2]);
	arg.time_to_eat = ft_atoi(av[3]);
	arg.time_to_sleep = ft_atoi(av[4]);
	arg.must_eat_count = 1;
	if (av[5] != NULL)
		arg.must_eat_count = ft_atoi(av[5]);
	return (arg);
}

void	philo(char	**av)
{
	t_arg	arg;

	arg = init_arg(av);
}
