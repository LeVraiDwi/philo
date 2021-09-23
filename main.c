#include "thread.h"

static void	*ft_announce(void *p_data)
{
	t_mut	*mutest;
	int		*j;

	mutest = (t_mut *)p_data;
	pthread_mutex_lock(&mutest->mutex);
	j = (int *)malloc(sizeof(int) * 1);
	if (j == 0)
		return (0);
	printf("Ce prepare a faire sont annonce\n");
	mutest->i = mutest->i + 1;
	printf("salut les amis c'est squeezi, cette video numero %d est sponso lol mdr\n", mutest->i);
	*j = mutest->i;
	usleep(5000000);
	pthread_mutex_unlock(&mutest->mutex);
	return ((void*)j);
}

int main()
{
	t_announce 	youteubeur[5];
	t_mut		mutest;
	int			i;
	int			*j;

	i = 0;
	pthread_mutex_init(&mutest.mutex, NULL);
	mutest.i = 0;
	while (i < 5)
	{
		youteubeur[i].name = i;
		if (pthread_create(&youteubeur[i].thread, 0, ft_announce, (void *)&mutest))
		{
			printf("Error\n");
			return (0);
		}
		printf("%lu\n", youteubeur[i].thread);
		i++;
	}
	printf("fin alloc\n");
	i = 0;
	while (i < 5)
	{
		printf("commence\n");
		pthread_join(youteubeur[i++].thread, (void **)&j);
		printf("pid:%d: fin annonce %d\n", youteubeur[i].name, *j);
		free(j);
	}
	pthread_mutex_destroy(&mutest.mutex);
	return (1);	
}
