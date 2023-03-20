#include "stddef.h"

#include "kernel/types.h"
#include "user/user.h"

int main() {
  uint pid = fork(); 
  printf("me: %d\n", pid); 
  
  if(pid != 0) {
  
    printf("I'm parent\n");
    int status;
    wait(&status);
    printf("child finished: %d\n", status);
    
  } else {
  
    printf("I'm child\n");
    sleep(10);
    
  }
  
  return 0;
}
