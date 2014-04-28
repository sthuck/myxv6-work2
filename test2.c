#include "types.h"
#include "user.h"
#include "uthread.h"

void tester(void* a) {
	int i=0;
	for (i=0;i<50;i++) {
		printf(1,"thread id %d printed for %d time\n",uthred_self(),i);
	}
	//uthread_exit();
}

int
main(int argc, char *argv[])
{
uthread_init();
int tid1 = uthread_create(tester,0);
//int tid2 = uthread_create(tester,0);
//int tid3 = uthread_create(tester,0);
uthred_join(tid1);
//uthred_join(tid2);
//uthred_join(tid3);
exit();

}