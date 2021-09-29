#include "philosopher.h"

int	ft_create_fork(int nb_philo, t_fork **array_fork)
{
	int	i;
	
	i = 0;
	while (i < nb_philo)
	{
		array_fork[i] = (t_fork *)malloc(sizeof(t_fork ) * nb_philo);
		if (!*array_fork)
			return (ft_free_fork(i - 1, array_fork));
		if(!ft_init_fork(array_fork[i]))
			return (ft_free_fork(i, array_fork));
		i++;
	}
	return (1);
}

int	ft_create_philo(t_setting *setting, t_fork *array_fork, t_philosophe **philo)
{
	int	i;

	i = 0;
	while (i < setting->time[0])
	{
		philo[i] = (t_philosophe *)malloc(sizeof(t_philosophe) * setting->time[0]);
		if (!*philo)
			return (ft_free_philo(i - 1, philo));
		ft_init_philo(philo[i], setting, array_fork, i);
		i++;
	}
	return (1);
}

int	ft_set_table(t_setting *setting, t_philosophe ***philo, t_fork ***array_fork)
{
		*array_fork = (t_fork **)malloc(sizeof(t_fork *) * setting->time[0]);
		if (!*array_fork)
			return (ft_error(1));
		if (!ft_create_fork(setting->time[0], *array_fork))
			return (ft_error(1));
		*philo = (t_philosophe **)malloc(sizeof(t_philosophe *) * setting->time[0]);
		if (!*philo)
		{
			ft_free_fork(setting->time[0], *array_fork);
			return (ft_error(2));
		}
		if (!ft_create_philo(setting, **array_fork, *philo))
		{
			ft_free_fork(setting->time[0], *array_fork);
			return(ft_error(2));
		}
		return (1);
}
