
#include "types.h"
#include "user.h"
#include "uthread.h"

uthread_p t_table;
int current_thread;

int
uthread_init() {
	t_table = malloc(MAX_THREAD*sizeof(uthread));
	int i = 0 ;
	for (i=0;i<MAX_THREAD;i++)
		t_table[i].state=T_SLEEPING;
	signal(14,uthread_yield);
	alarm(5);

}