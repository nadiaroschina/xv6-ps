
## xv6-ps
xv6 is a lightweight operating system developed to help in OS learning 
(see [XV6-README](./XV6-README.md)).
Existing funcionality is very basic, 
and the rest is left for the developer to fill in.

## ps util

Print information about the processes in the system in one of the following formats:

usage: 

```console
$ ps count
```

Get the total number of processes in the system

```console
$ ps pids <pids> <limit>
```

Fill no more than `limit` int values at `pids` program address
with numbers of current processes.


The return value is 0 when everything finished as expected, 
and the 1 and -1 error codes signal about user error in command format
 and internal system error respectively.

```console
$ ps list 
```

Prints information about all the processses, their names, states, parents, memory and
files limits, run time and number of system context switches.

### Implementation

The main functions handling this programm are
the `ps_list` and `ps_info` system calls, 
realized in `kernel/sysfile.c`, and the functions in 
`kernel/proc.c` to deal with processes.

The initial `proc` structure was modified to store information about 
program running times, and in `kernel/process_info.h` an auxiliary struct 
was added.


### usae exaple 

```console
$ ps list
info about pid = 1:
state = sleep 
parent_id = 0
mem_size = 16384 bytes
files_count = 3
proc_name = init
proc_ticks = 20
run_time = 0
context_switches = 14
ps_info return value = 0

info about pid = 2:
state = sleep 
parent_id = 1
mem_size = 20480 bytes
files_count = 3
proc_name = sh
proc_ticks = 19
run_time = 0
context_switches = 13
ps_info return value = 0

info about pid = 3:
state = run   
parent_id = 2
mem_size = 16384 bytes
files_count = 3
proc_name = ps
proc_ticks = 1
run_time = 0
context_switches = 6
ps_info return value = 0

```
