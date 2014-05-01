#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "signal.h"
#include "uthread.h"

void test(void *binary_semaphore){
 int i = 0;
      for (i=50; i< 60; i++){
   	   printf(1, "%d\n", i);
   	   sleep(20);
      }


}

void test2(void *binary_semaphore){
int j;
for (j=0; j<10000000; j++){}
 int i = 0;
 	 binary_semaphore_down((struct binary_semaphore*) binary_semaphore);
      for (i=0; i< 10; i++){
   	   printf(1, "%d\n", i);
   	   sleep(20);
      }
       binary_semaphore_up((struct binary_semaphore*) binary_semaphore);


}
int main(int argc,char** argv){
       uthread_init();
       struct binary_semaphore *binary_semaphore = (struct binary_semaphore*)malloc(sizeof (struct binary_semaphore));
       binary_semaphore_init(binary_semaphore,1);
       int tid = uthread_create(test,  (void*) binary_semaphore);
       if (!tid)
               goto out_err;
       tid = uthread_create(test2, (void *) binary_semaphore);
       if (!tid)
               goto out_err;
       tid = uthread_create(test, (void *) binary_semaphore);
            if (!tid)
                goto out_err;
//       tid = uthread_create(test, (void *) 4);
//              if (!tid)
//                 goto out_err;

         int i = 0;
          for (i =0  ; i<1000000000 ; i++){
//        	   if (i==10000000){
//        	   tid = uthread_create(test, (void *) 5);
//        	                if (!tid)
//        	                    goto out_err;
//        	   }
          }
          //printThreadTable();
          exit();
          out_err:
          printf(1,"Failed to create thread, we go bye bye\n");
          exit();
} 