#include "philosopher.h"

int	ft_create_fork(int nb_philo, t_fork **array_fork)
{
	int	i;
	
	i = 0;
	printf("fork\n");
	while (i < nb_philo)
	{
		array_fork[i] = (t_fork *)malloc(sizeof(t_fork ) * nb_philo);
		if (!*array_fork)
			return (ft_free_fork(nb_philo, array_fork));
		if(!ft_init_fork(array_fork[i]))
			return (ft_free_fork(nb_philo, array_fork));
		array_fork[i]->num = i;
		i++;
	}
	return (1);
}

int	ft_create_philo(t_setting setting, t_fork *array_fork, t_philosophe **philo)
{
	int	i;

	i = 0;
	while (i < setting.time[0])
	{
		philo[i] = (t_philosophe *)malloc(sizeof(t_philosophe) * setting.time[0]);
		if (!*philo)
			return (0);
		ft_init_philo(philo[i], &setting, array_fork, i);
	//	printf("fin init %d < %d\n", i, setting.time[0]);
		i++;
	}
	return (1);
}
