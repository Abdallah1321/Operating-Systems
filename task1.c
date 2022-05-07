#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// min and max used to have constant values which are the ranges of which value the pid can take

int min  = 300;
int max = 4000;

// an array is used to store pid's

int pid [3701];
int last; 

int allocate_map(void){
  for (int i = 0; i <=(max - min) + 1; i++) {
    pid[i] = 0;
  }
  if (pid[3700] == 0){
      return 1; //Success
  }
  else{
      return -1; //Fail
  }
}

int allocate_pid(void){
    int next;
    int i;
    next = last + 1;
    while((i <= (max - min)) && (pid[next] == 1)){
        i++;
        next++;
        if (next > 3701){
            next = min - 300;
        }
    }

    if (i == (max - min) + 1){
        return -1; // No pid available
    }
    

    pid[next] = 1;
    last = next;
    return 1;

}

void release_pid(int pidV) {
    pid[pidV - min] = 0;
    printf("PID [%d] has been released \n", pidV);
}

int main(){
	allocate_map();
	allocate_pid();
    allocate_pid();
	
	int x = 0;
	
	for (int i = 0; i < (max - min) + 1; i++) {
		if(pid[i] == 1){
			printf("PID [%d] status: %d\t \n", i + 300, pid[i]);
			x++;
		}
	}
    release_pid(301);
    printf("Check new PID status \n");
    for (int i = 0; i < (max - min) + 1; i++) {
		if(pid[i] == 1){
			printf("PID [%d] status: %d\t \n", i + 300, pid[i]);
			x++;
		}
	}

    printf("\nAllocating all pids \n");
    for (int i = 0; i < (max-min) + 1; i++){
        allocate_pid();
    }
	
    printf("return value of function %d \n", allocate_pid());
	return 0;
}