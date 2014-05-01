#include "types.h"
#include "user.h"
#include "uthread.h"

#define Q 0
#define P 1
#define R 2
#define Z 3
#define M 4
#define X 5
#define F 6
#define NA 7	

const int numToState[] = {'Q','P','R','Z','M','X','F','N'};
int stateTable[5][6][6];
void 
initialize(){
	#include "stateTable.inc"
}

#include "barier.c"
struct barrier readB;
struct barrier writeB;
int N=0;
int *stateArr;

int checkAllF() {
	int res = 1;
	int i=0;
	for (i=0;i<N;i++) {
		if (stateArr[i]!=F) {
			res = 0;
			break;
		}
	}
	return res;
}

void threadMain(void* arg) {
	int i = (int)arg;
	int next;
	while (1) {
		if (i==0)
			next = stateTable[stateArr[i]][X][stateArr[i+1]];
		else if (i==N-1) //right end
			next = stateTable[stateArr[i]][stateArr[i-1]][X];
		else 
			next = stateTable[stateArr[i]][stateArr[i-1]][stateArr[i+1]];

		do_barrier(&readB); //done reading
		stateArr[i]=next;
		do_barrier(&writeB); //done writing
		if (next==F)
			uthread_exit();
	}
}

int main(int argc, char **argv)
{
	if(argc < 2){
		printf(2,"Pass number of soldiers\n"); 
		exit();
	}
	else {
		N = atoi(argv[1]);
		if(N > MAX_THREAD-1 || N <= 0) {
		  printf(2,"illeagel input\n"); 
		  exit();
		}
	}
	int i;
	init_barrier(&readB,N+1);
	init_barrier(&writeB,N+1);
	initialize();
	uthread_init();
	stateArr = (int*)malloc(N * sizeof(int));
	for(i = 1; i < N; i++){
		stateArr[i] = Q;
	}
	stateArr[0]=P; //general! 
	for(i = 0; i < N; i++){
		uthread_create(threadMain, (void*)i);
	}

	while(1) {
		for (i=0;i<N;i++)
			printf(1,"%c",numToState[stateArr[i]]);
		printf(1,"\n");
		if (checkAllF()) {
			printf(1,"Finished!\n");
			exit();
		}
		do_barrier(&readB); //done reading
		do_barrier(&writeB); //done writing
	}
	
}
