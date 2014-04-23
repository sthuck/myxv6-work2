#include "types.h"
#include "user.h"


void death(void);
int
main(int argc, char *argv[])
{
int pid;
void (*fp)(void) = death;
printf(2,"death = %d",(int)fp);

pid = fork();
if (pid==0) {
	printf(2,"death = %d",(int)fp);
	signal(5,death);
	while(1);
}
	sleep(100);
	int j = sigsend(pid,5);
	printf(2,"return val %d",j);
	wait();
return 0;
}

void death(void) {
	printf(2,"DEATH DEATH DEATH\n");
}