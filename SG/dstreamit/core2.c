#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <pthread.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#include "globals.h"
#include "barrier.h"
#include "rdtsc.h"
#include "structs.h"
using namespace _smpsg_internal;


// code for core 2


void * __main____15(void * arg__16);




void buffer_and_address_init__n2() {
  barrier.wait();
}


void * __main____15(void * arg__16) {
  setCPUAffinity(2);
  buffer_and_address_init__n2();
  barrier.wait_block();

  while (1) {
    /* Steady-State Barrier */;
    barrier.wait();
    /* Steady-State Barrier */;
    barrier.wait();
  }
  pthread_exit(NULL);
}
