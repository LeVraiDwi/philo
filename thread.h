#ifndef THREAD_H
# define THREAD_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_mut
{
	pthread_mutex_t	mutex;
	int						i;
	int						yt;
}				t_mut;

typedef struct	s_announce
{
	pthread_t 	thread;
	int					name;
}				t_announce;

#endif
