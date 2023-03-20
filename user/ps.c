#include "stddef.h"

#include "kernel/types.h"
#include "kernel/process_info.h"
#include "user/user.h"

void
main(int argc, char *argv[]) {

	if (argc <= 1) {
	  printf("use \"ps count\", \"ps pids <limit> <pids>\" or \"ps list\"\n");
	  exit(0);
	}
	
	if (!strcmp(argv[1], "count")) {
	
	  if (argc != 2) {
	    printf("ps count: wrong number of arguments; expected 2, got %d\n", argc);
	    exit(1);
	  }
	
	  int proc_cnt = ps_list(-1, NULL);
	  
	  if (proc_cnt == -1) {
	    printf("error\n");
	    exit(-1);
	  } 
	  else {
	    printf("%d\n", proc_cnt);
	  }
	  
	}
	
	else if (!strcmp(argv[1], "pids")) {
	
	  if (argc != 4) {
	    printf("ps pids <limit> <pids>: wrong number of arguments; expected 4, got %d\n", argc);
	    exit(1);
	  }
	
	  int limit = atoi(argv[2]);
	  int* pids = (int*) (uint64) atoi(argv[3]);
	  
	  int proc_cnt = ps_list(limit, pids);
	  if (proc_cnt == -1) {
	    printf("error\n");
	    exit(-1);
	  }
	  else {
	  printf("%d\n", proc_cnt);
	    for (int i = 0; i < limit; ++i) {
	      printf("%d\n", pids[i]);
	    }
	  }
	   
	}
	
	else if (!strcmp(argv[1], "my_pids")) {
	
	 // for tests
	 
	 int limit = 10;
	  
	  int my_pids[limit];
	  for (int i = 0; i < limit; ++i) {
	    my_pids[i] = -1;
	  }
	  
	  int res = ps_list(limit, my_pids);
	  printf("%d\n", res);
	  for (int i = 0; i < limit; ++i) {
	    printf("%d\n", my_pids[i]);
	  }
	  
	}
	
	else if (!strcmp(argv[1], "list")) {
	
	  if (argc != 2) {
	    printf("ps count: wrong number of arguments; expected 2, got %d\n", argc);
	    exit(1);
	  }
	 
	  int my_limit = 100;
	  int my_pids[my_limit];
	  for (int i = 0; i < my_limit; ++i) {
	    my_pids[i] = -1;
	  }
	  
	  int proc_cnt = ps_list(my_limit, my_pids);
	  if (proc_cnt > my_limit) {
	    printf("too many processes\n");
	    exit(-1);
	  }
	  
	  for (int i = 0; i < proc_cnt; ++i) {
	  
	    struct process_info psinfo = {};
	    int res = ps_info(my_pids[i], &psinfo);
	    
	    if (res == -1) {
	    
	      printf("cannot get info about pid = %d\n\n", my_pids[i]);
	      
	    }
	    else {
	    
	     printf("info about pid = %d:\n", my_pids[i]);
	     printf("state = %s\n", psinfo.state);
	     printf("parent_id = %d\n", psinfo.parent_pid);
	     printf("mem_size = %d bytes\n", psinfo.mem_size);
	     printf("files_count = %d\n", psinfo.files_count);
	     printf("proc_name = %s\n", psinfo.proc_name);
	     printf("proc_ticks = %d\n", psinfo.proc_ticks);
	     printf("run_time = %d\n", psinfo.run_time);
	     printf("context_switches = %d\n", psinfo.context_switches);
	     printf("ps_info return value = %d\n", res);
	     printf("\n");
	     
	    }
	  } 
	  
	} else {
	
	  printf("unknown command: ps %s\n", argv[1]);
	  exit(1);
	
	}
	
	exit(0);
	
}
