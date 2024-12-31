/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:40:02 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 16:40:03 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FG_GREEN "\001\033[92m\002"
# define FG_RED "\001\033[91m\002"
# define ANSI_COLOR_RESET "\x1b[0m"

typedef struct s_data	t_data;

typedef struct s_philo
{
	size_t				time_to_eat;
	size_t				start_time;
	size_t				start;
	int					meals_eaten;
	size_t				start_time_sleep;
	size_t				end_time;
	size_t				time_to_sleep;
	size_t				time_to_die;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	int					index;
	pthread_t			th1;
	t_data				*my_data;
}						t_philo;

typedef struct s_data
{
	int					num_philo;
	int					count_meal;
	int					num_fork;
	int					flag;
	pthread_mutex_t		lock;
	int					num_frok;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					num_meal;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}						t_data;
size_t					get_current_time(void);
int						take_forks(t_philo *phil, pthread_mutex_t *first,
							pthread_mutex_t *second);
int						ft_usleep(size_t milliseconds);
int						ft_parsing(t_data *data, char **av);
int						locked_print(char *msg, t_philo *phil);
int						ft_atoi(char *av);
int						create_philosophers(t_data *data);
void					join_threads(t_data *data, t_philo *philo);
int						initialize_mutexes(t_data *data);
void					*routine(void *philo);
void					monitor_philosophers(t_data *data, t_philo *philo);
int						check_simulation_end(t_philo *phil);
int						eat(t_philo *phil);
int						phil_sleep(t_philo *phil);
int						handle_single_philosopher(t_philo *phil);
int						handle_fork_taking(t_philo *phil);
int						check_meal_count(t_philo *phil);
int						philosopher_routine(t_philo *phil);
void					cleanup_mutexes(t_data *data);
int						think(t_philo *phil);
void					cleanup_resources(t_data *data);
int						create_and_monitor_philosophers(t_data *data);
int						initialize_simulation(t_data *data);
int						allocate_memory(t_data *data);
int						validate_arguments(int argc);

#endif