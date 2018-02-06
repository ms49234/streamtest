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


// Global barrier
barrier_t barrier(0);

// Set CPU affinity for thread
void setCPUAffinity(int core) {
  cpu_set_t cpu_set;
  CPU_ZERO(&cpu_set);
  CPU_SET(core, &cpu_set);

  if(pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpu_set) != 0) {
    printf("\nWarning: setting pthread affinity failed...\n");
  }
}

pthread_t thread_n0;
pthread_t thread_n1;
pthread_t thread_n2;
pthread_t thread_n3;

int VectorDist_sgate_fire() {

  barrier.release_blocking();

  return 1;
}

int VectorDist_sgate_synchronize() {

  barrier.wait_for_all_blocked();

  return 1;
}

int VectorDist_sgate_init() {

  // Initialize barrier
  barrier = barrier_t(4);

  // Spawn threads
  int rc;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  if ((rc = pthread_create(&thread_n0, NULL, __main____4, (void *)NULL)) < 0) { return 0; }

  if ((rc = pthread_create(&thread_n1, NULL, __main____13, (void *)NULL)) < 0) { return 0; }

  if ((rc = pthread_create(&thread_n2, NULL, __main____15, (void *)NULL)) < 0) { return 0; }

  if ((rc = pthread_create(&thread_n3, NULL, __main____17, (void *)NULL)) < 0) { return 0; }

  pthread_attr_destroy(&attr);

  VectorDist_sgate_synchronize();

  return 1;
}

int VectorDist_sgate_exit() {

  VectorDist_sgate_synchronize();

  barrier.exit();

  int rc;
  void *status;
  int jst = 1;

  if ((rc = pthread_join(thread_n0, &status)) < 0) { jst = 0; }

  if ((rc = pthread_join(thread_n1, &status)) < 0) { jst = 0; }

  if ((rc = pthread_join(thread_n2, &status)) < 0) { jst = 0; }

  if ((rc = pthread_join(thread_n3, &status)) < 0) { jst = 0; }

  return jst;
}

int VectorDist_sgate_assign_memr_in_buff(float *buffer, unsigned int size) {

  __sgate_memr_buff_in_buff = buffer;
  __sgate_memr_size_in_buff = size;

  __sgate_memr_itlc_in_buff_0 = 0;

  __sgate_memr_iter_in_buff = 0;

  return 1;
}

int VectorDist_sgate_get_index_memr_in_buff() {

  return __sgate_memr_iter_in_buff;
}

int VectorDist_sgate_get_tcon_memr_in_buff() {

  return __sgate_memr_tcon_in_buff;
}

int VectorDist_sgate_set_loop_memr_in_buff(bool loop) {

  __sgate_memr_loop_in_buff = loop;

  return 1;
}

extern const int VectorDist_sgate_min_size_memr_in_buff = 16;

int VectorDist_sgate_assign_memw_out_buff(float *buffer, unsigned int size) {

  __sgate_memw_buff_out_buff = buffer;
  __sgate_memw_size_out_buff = size;


  __sgate_memw_iter_out_buff = 0;

  return 1;
}

int VectorDist_sgate_get_index_memw_out_buff() {

  return __sgate_memw_iter_out_buff;
}

int VectorDist_sgate_get_tcon_memw_out_buff() {

  return __sgate_memw_tcon_out_buff;
}

int VectorDist_sgate_set_loop_memw_out_buff(bool loop) {

  __sgate_memw_loop_out_buff = loop;

  return 1;
}

extern const int VectorDist_sgate_min_size_memw_out_buff = 8;
