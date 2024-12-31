/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:39:44 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 17:03:18 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_single_philosopher(t_philo *phil)
{
	pthread_mutex_lock(phil->l_fork);
	if (locked_print("has taken a fork", phil))
	{
		pthread_mutex_unlock(phil->l_fork);
		return (1);
	}
	ft_usleep(phil->time_to_die);
	pthread_mutex_unlock(phil->l_fork);
	return (1);
}

int	handle_fork_taking(t_philo *phil)
{
	if (phil->index % 2 == 0)
		return (take_forks(phil, phil->r_fork, phil->l_fork));
	else
	{
		if (phil->my_data->num_philo == 1)
			return (handle_single_philosopher(phil));
		return (take_forks(phil, phil->l_fork, phil->r_fork));
	}
}

int	check_meal_count(t_philo *phil)
{
	pthread_mutex_lock(&phil->my_data->lock);
	if (phil->my_data->num_meal != -1
		&& phil->meals_eaten == phil->my_data->num_meal)
	{
		phil->my_data->count_meal++;
		pthread_mutex_unlock(&phil->my_data->lock);
		return (1);
	}
	pthread_mutex_unlock(&phil->my_data->lock);
	return (0);
}

int	philosopher_routine(t_philo *phil)
{
	if (phil->index % 2 == 1)
		usleep(500);
	if (check_simulation_end(phil))
		return (1);
	if (handle_fork_taking(phil))
		return (1);
	if (eat(phil))
		return (1);
	if (check_meal_count(phil))
		return (1);
	if (phil_sleep(phil))
		return (1);
	if (think(phil))
		return (1);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	while (1)
	{
		if (philosopher_routine(phil))
			break ;
	}
	return (NULL);
}
