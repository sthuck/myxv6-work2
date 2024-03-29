/*
 * ticketSeller.c
 * ---------------
 * A very simple example of a critical section that is protected by a
 * semaphore lock. There is a global variable numTickets which tracks the
 * number of tickets remaining to sell. We will create many threads that all
 * will attempt to sell tickets until they are all gone. However, we must
 * control access to this global variable lest we sell more tickets than
 * really exist. We have a semaphore lock that will only allow one seller
 * thread to access the numTickets variable at a time. Before attempting to
 * sell a ticket, the thread must acquire the lock by waiting on the semaphore
 * and then release the lock when through by signalling the semaphore.
 */

#include "types.h"
#include "stat.h"
#include "user.h"
#include "uthread.h"

#define NUM_TICKETS 50
#define NUM_SELLERS 20

void SellTickets(void*);

/**
 * The ticket counter and its associated lock will be accessed
 * all threads, so made global for easy access.
 */
static int numTickets = NUM_TICKETS;
static struct binary_semaphore ticketsLock;

static int randomSleeps[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
         29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71,
         73 , 79 , 83 , 89 , 97 , 101 , 103 , 107 , 109 , 113,
         127 , 131 , 137 , 139 , 149 , 151 , 157 , 163 , 167 , 173};

int main(int argc, char **argv)
{
 int i;
 uthread_init();
 binary_semaphore_init(&ticketsLock, 1);

 printf(1, "Creating threads\n");
 for (i = 0; i < NUM_SELLERS; i++)
    uthread_create(SellTickets, randomSleeps + i);

 printf(1, "Start selling\n");

for (i = 1; i <= NUM_SELLERS; i++)
    uthred_join(i);

 printf(1, "All done!\n");
 uthread_exit();
 exit(); // satisfy gcc
}

static void delay(int i) {
    int j;
    for (j=0; j<i; j++)
        ;
}

/**
 * SellTickets
 * -----------
 * This is the routine forked by each of the ticket-selling threads.
 * It will loop selling tickets until there are no more tickets left
 * to sell. Before accessing the global numTickets variable,
 * it acquires the ticketsLock to ensure that our threads don't step
 * on one another and oversell on the number of tickets.
 */
void SellTickets(void* arg)
{
 int done = 0;
 int numSoldByThisThread = 0; // local vars are unique to each thread
 int sleepArg = *(int*)arg;

 while (done == 0) {
    delay(sleepArg*1000000);
    binary_semaphore_down(&ticketsLock);
    if (numTickets == 0) {
        // here is safe to access numTickets
        done = 1;
    } else {
        numTickets--;
        numSoldByThisThread++;
        printf(1, "%d sold one (%d left)\n", uthred_self(), numTickets);
         // בשביל לתת הזמדנות לתרדים להכנס לתור
    }
    binary_semaphore_up(&ticketsLock);
    delay(sleepArg*1000000);
 }
 printf(1, "%d noticed all tickets sold! (I sold %d myself) \n", uthred_self(), numSoldByThisThread);
}
