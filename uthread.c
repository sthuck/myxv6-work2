
#include "types.h"
#include "user.h"
#include "uthread.h"

uthread_p t_table;
int current_thread=-1;

int
uthread_init(void) {
	t_table = malloc(MAX_THREAD*sizeof(uthread_t));
	if (t_table==0)
		return -1;
	int i = 0 ;
	for (i=0;i<MAX_THREAD;i++) {
		t_table[i].state=T_FREE;
		t_table[i].tid=i;
	}
	current_thread=0;
	t_table[0].state=T_RUNNING;
	t_table[0].stack=0;
	signal(14,uthread_yield);
	alarm(THREAD_QUANTA);
	return 0;
}

int
getNextFreeThread(void) {
	int i;
	for (i=0;i<MAX_THREAD;i++) 
		if (t_table[i].state==T_FREE)
			return i;
	return -1;
}

int
getNextRunnableThread(void) {
	int i;
	for (i=0;i<MAX_THREAD;i++) 
		if (t_table[(i+1+current_thread)%MAX_THREAD].state==T_RUNNABLE)
			return (i+1+current_thread)%MAX_THREAD;
	return -1;
}

int  
uthred_self(void) {
    return current_thread;
}


void 
uthread_yield(void) {
	uthread_p this = &t_table[current_thread];
	this->state=T_RUNNABLE;
	STORE_ESP(this->esp);
    STORE_EBP(this->ebp);
    PUSHAL;
    int next = getNextRunnableThread();
    t_table[next].state=T_RUNNING;
    current_thread=next;
    LOAD_EBP(t_table[current_thread].ebp);
    LOAD_ESP(t_table[current_thread].esp);
    POPAL;
    alarm(THREAD_QUANTA);
    return ;
}

int 
uthread_create(void (*func)(void *), void* arg) {
	int tid = getNextFreeThread();
	if (tid==-1) {
		printf(2,"No more threads can be created\n");
		return -1;
	}
	t_table[tid].tid=tid;
	t_table[tid].state=T_RUNNABLE;
	t_table[tid].stack=malloc(STACK_SIZE);
	*(t_table[tid].stack+STACK_SIZE-4) = (int)arg;
	*(t_table[tid].stack+STACK_SIZE-8) = (int)uthread_exit;
	*(t_table[tid].stack+STACK_SIZE-12) = 0;  //fake old ebp, doesnt matter
	*(t_table[tid].stack+STACK_SIZE-16) = (int)func;
	*(t_table[tid].stack+STACK_SIZE-20)=(int)t_table[tid].stack+STACK_SIZE-12     ;//"old ebp" - will go to ebp
	*(t_table[tid].stack+STACK_SIZE-24)=0; // eax ;
	*(t_table[tid].stack+STACK_SIZE-28)=0; // ebx
	*(t_table[tid].stack+STACK_SIZE-32)=0; // ecx
	*(t_table[tid].stack+STACK_SIZE-36)=0; // edx
	*(t_table[tid].stack+STACK_SIZE-40)=0; // edi
	*(t_table[tid].stack+STACK_SIZE-44)=0; // esi
	t_table[tid].esp=(int)t_table[tid].stack+STACK_SIZE-44;
	t_table[tid].ebp=(int)t_table[tid].stack+STACK_SIZE-20;  
	return tid; 
}


void 
uthread_exit(void) {
	int next = getNextRunnableThread();
	if (next==-1) {
		printf(2,"last thread finished!\n");
		exit();
	}
	
	printf(2,"thead %d exited properly\n",current_thread);
	free(t_table[current_thread].stack);
	t_table[current_thread].state=T_FREE;

	printf(2,"found next tid %d\n",next);
    t_table[next].state=T_RUNNING;
    current_thread=next;
    LOAD_EBP(t_table[next].ebp);
    LOAD_ESP(t_table[next].esp);
    POPAL;
    alarm(THREAD_QUANTA);
    return ;
}

int 
uthred_join(int tid) {
	if (tid>MAX_THREAD)
		return 1;
	while(1) {
		if (t_table[tid].state==T_FREE)
			return 0;
		uthread_yield();
	}
}
