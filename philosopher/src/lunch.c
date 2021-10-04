#include "philosopher.h"

int	lunch_time(t_setting *setting, t_philosophe **philo)
{
	int			i;
	int			j;
	pthread_t	thread;

	i = 0;
	j = 0;
	if(gettimeofday(&philo[0]->setting->start, NULL) == -1)
		return (0);
	setting->end = 0;
	while (i < philo[0]->setting->time[0])
	{
		philo[i]->name = i + 1;
		if (pthread_create(&philo[i]->thread, 0, ft_philo, (void *)philo[i]))
			return (0);
		i++;
	}
	if(pthread_create(&thread, 0, ft_check, (void *)philo))
		return (0);
	if (pthread_detach(thread))
		return (0);
	i = 0;
	while (i < philo[0]->setting->time[0])
	{
		if (pthread_join(philo[i]->thread, (void *)&j))
			return (0);
		i++;
	}
	return (1);
}
