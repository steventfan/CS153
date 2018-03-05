#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int PScheduler(void);
  int DScheduler(int);

  printf(1, "\n This program tests the correctness of your lab#2\n");
        
  if(argc <= 1){
    PScheduler();
  }
  else if(argc == 2){
    DScheduler(3); //donation amount
  }
  exit(0);
}  
    
int PScheduler(void){
		 
  // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 63
  // 0 is the highest priority. All processes have a default priority of 20 

  int pid;
  int i,j,k;
  int exit_status;
  
  printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int pid, int priority)) systema call:\n");
  printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
  printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
  printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
  setpriority(getpid(), 0);
  for (i = 0; i <  3; i++) {
    pid = fork();
    if (pid > 0 ) {
      continue;}
    else if ( pid == 0) {
      setpriority(getpid(), 30-10*i);	
      for (j=0;j<50000;j++) {
        for(k=0;k<10000;k++) {
          asm("nop");
        }
      }
      printf(1, "\n child# %d with priority %d has finished! \n",getpid(),30-10*i);		
      exit(0);
    }
    else {
      printf(2," \n Error \n");			
    }
  }
  if(pid > 0) {
    for (i = 0; i <  3; i++) {
      wait(&exit_status);
    }
    printf(1,"\n if processes with highest priority finished first then its correct \n");
  }
			
  return 0;
}

int DScheduler(int value){
  int parent, pid, exit_status, i, j;

  printf(1, " \n Testing priority donation \n ");
  setpriority(getpid(), 20);
  parent = getpid();
  printf(1, " \n This is process %d with priority %d \n ", getpid(), getpriority() );
  pid = fork();
  if(pid > 0){
    wait(&exit_status);
    printf(1, " \n process %d now has priority %d after donation \n ", getpid(), getpriority() );
  }
  else if(pid == 0){
    setpriority(getpid(), 10);
    printf(1, " \n This is process %d with priority %d \n ", getpid(), getpriority() );
    for(i = 0; i < 50000; i++){
      for(j = 0; j < 10000; j++){
        asm("nop");
      }
    }
    printf(1, " \n process %d is now donating %d priority to process %d \n ", getpid(), value, parent);
    donate(parent, value);
    for(i = 0; i < 50000; i++){
      for(j = 0; j < 10000; j++){
        asm("nop");
      }
    }
    printf(1, " \n process %d now has priority %d after donation \n ", getpid(), getpriority() );
    exit(0);
  }
  else{
    printf(2, " \n Error \n ");
  }

  return 0;
}
