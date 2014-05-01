struct barrier {
	struct binary_semaphore arrvial;
	struct binary_semaphore departure;
	int N;
	int counter;
};

void init_barrier(struct barrier* ber ,int n) {
	binary_semaphore_init(&ber->arrvial,1);
	binary_semaphore_init(&ber->departure,0);
	ber->N=n;
	ber->counter=0;
} 

void do_barrier(struct barrier* ber) {
	binary_semaphore_down(&ber->arrvial);
	ber->counter++;
	if (ber->counter < ber->N)
		binary_semaphore_up(&ber->arrvial);
	else
		binary_semaphore_up(&ber->departure);
	binary_semaphore_down(&ber->departure);
	ber->counter--;
	if (ber->counter>0)
		binary_semaphore_up(&ber->departure);
	else
		binary_semaphore_up(&ber->arrvial);
}