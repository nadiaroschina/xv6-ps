#include "stddef.h"

#include "kernel/types.h"
#include "user/user.h"

void
main(int argc, char *argv[]) {

	if (argc <= 1) {
	  printf("use \"ps count\" or \"ps pids <limit> <pids>\"\n");
	  exit(0);
	}
	
	if (!strcmp(argv[1], "count")) {
	
	  if (argc != 2) {
	    printf("ps count: wrong number of arguments; expected 2, got %d\n", argc);
	    exit(1);
	  }
	
	  int res = ps_list(-1, NULL);
	  printf("%d\n", res);
	  
	}
	
	else if (!strcmp(argv[1], "pids")) {
	
	  if (argc != 4) {
	    printf("ps pids <limit> <pids>: wrong number of arguments; expected 4, got %d\n", argc);
	    exit(1);
	  }
	
	  int limit = atoi(argv[2]);
	  int* pids = (int*) (uint64) atoi(argv[3]);
	  
	  int res = ps_list(limit, pids);
	  if (res == -1) {
	    printf("error\n");
	    exit(-1);
	  }
	  else {
	  printf("%d\n", res);
	    for (int i = 0; i < limit; ++i) {
	      printf("%d\n", pids[i]);
	    }
	  }
	  
	  /*
	  
	  // for tests
	  
	  int my_pids[limit];
	  for (int i = 0; i < limit; ++i) {
	    my_pids[i] = -1;
	  }
	  
	  int res = ps_list(limit, my_pids);
	  printf("%d\n", res);
	  for (int i = 0; i < limit; ++i) {
	    printf("%d\n", my_pids[i]);
	  }	
	  
	  */ 
	  
	}
	
	exit(0);
	
}
