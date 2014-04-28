#include "types.h"
#include "user.h"
#include "uthread.h"

void tester(void* a) {
	int i=0;
	for (i=0;i<50;i++) {
		printf(1,"thread id %d, got %d, printed for %d time\n",uthred_self(), *((int*)a), i);
	}
	//uthread_exit();
}

int
main(int argc, char *argv[])
{
uthread_init();
int stam = 10;
int stam1 = 12;
int stam2 = 20;
int tid1 = uthread_create(tester,&stam);
int tid2 = uthread_create(tester,&stam1);
int tid3 = uthread_create(tester,&stam2);
uthred_join(tid1);
uthred_join(tid2);
uthred_join(tid3);
exit();

}