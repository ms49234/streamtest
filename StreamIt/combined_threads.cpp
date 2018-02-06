#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <message.h>
#include <netsocket.h>
#include <node_server.h>
#include <init_instance.h>
#include <master_server.h>
#include <save_state.h>
#include <save_manager.h>
#include <delete_chkpts.h>
#include <object_write_buffer.h>
#include <read_setup.h>
#include <ccp.h>
#include <timer.h>
#include <streamit_random.h>
#include "structs.h"
#include "fusion.h"

int __max_iteration;
int __timer_enabled = 0;
int __frequency_of_chkpts;
volatile int __vol;
proc_timer tt("total runtime");


float BUFFER_0_1[__BUF_SIZE_MASK_0_1 + 1];
int HEAD_0_1 = 0;
int TAIL_0_1 = 0;
float BUFFER_1_2[__BUF_SIZE_MASK_1_2 + 1];
int HEAD_1_2 = 0;
int TAIL_1_2 = 0;
void init_VSource__4_4__0();
void work_VSource__4_4__0(int);
void init_Worker__10_5__1();
void work_Worker__10_5__1(int);
void init_FloatPopper__13_6__2();
void work_FloatPopper__13_6__2(int);

int main(int argc, char **argv) {
  read_setup::read_setup_file();
  __max_iteration = read_setup::max_iteration;
  for (int a = 1; a < argc; a++) {
    if (argc > a + 1 && strcmp(argv[a], "-i") == 0) {
      int tmp;
      sscanf(argv[a + 1], "%d", &tmp);
#ifdef VERBOSE
      fprintf(stderr,"Number of Iterations: %d\n", tmp);
#endif
      __max_iteration = tmp;
    }
    if (strcmp(argv[a], "-t") == 0) {
#ifdef VERBOSE
      fprintf(stderr,"Timer enabled.\n");
#endif
      __timer_enabled = 1;
    }
  }
// number of phases: 3


  // ============= Initialization =============

init_VSource__4_4__0();
init_Worker__10_5__1();
init_FloatPopper__13_6__2();

  // ============= Steady State =============

  if (__timer_enabled) {
    tt.start();
  }
  for (int n = 0; n < (__max_iteration  ); n++) {
HEAD_0_1 = 0;
TAIL_0_1 = 0;
    work_VSource__4_4__0(1 );
HEAD_1_2 = 0;
TAIL_1_2 = 0;
    work_Worker__10_5__1(1 );
    work_FloatPopper__13_6__2(1 );
  }
if (__timer_enabled) {
    tt.stop();
    tt.output(stderr);
  }


  return 0;
}

// moved or inserted by concat_cluster_threads.pl
message *__msg_stack_0;
message *__msg_stack_1;
message *__msg_stack_2;

// end of moved or inserted by concat_cluster_threads.pl

// peek: 0 pop: 0 push 2
// init counts: 0 steady counts: 1

// ClusterFusion isEliminated: false


#include <mysocket.h>
#include <sdep.h>
#include <thread_info.h>
#include <consumer2.h>
#include <consumer2p.h>
#include <producer2.h>
#include "cluster.h"
#include "global.h"

int __number_of_iterations_0;
int __counter_0 = 0;
int __steady_0 = 0;
int __tmp_0 = 0;
int __tmp2_0 = 0;
int *__state_flag_0 = NULL;
thread_info *__thread_0 = NULL;



float x__0__0 = 0.0f;
float y__1__0 = 0.0f;
void save_file_pointer__0(object_write_buffer *buf);
void load_file_pointer__0(object_write_buffer *buf);

inline void check_status__0() {
  check_thread_status(__state_flag_0, __thread_0);
}

void check_status_during_io__0() {
  check_thread_status_during_io(__state_flag_0, __thread_0);
}

void __init_thread_info_0(thread_info *info) {
  __state_flag_0 = info->get_state_flag();
}

thread_info *__get_thread_info_0() {
  if (__thread_0 != NULL) return __thread_0;
  __thread_0 = new thread_info(0, check_status_during_io__0);
  __init_thread_info_0(__thread_0);
  return __thread_0;
}

void __declare_sockets_0() {
  init_instance::add_outgoing(0,1, DATA_SOCKET);
}

void __init_sockets_0(void (*cs_fptr)()) {
  mysocket *sock;

}

void __flush_sockets_0() {
}

void __peek_sockets_0() {
}

 
void init_VSource__4_4__0();
inline void check_status__0();

void work_VSource__4_4__0(int);



inline void __push_0_1(float data) {
BUFFER_0_1[HEAD_0_1]=data;
HEAD_0_1++;
}



 
void init_VSource__4_4__0(){
  ((x__0__0) = ((float)0.0))/*float*/;
  ((y__1__0) = ((float)0.0))/*float*/;
}
void save_file_pointer__0(object_write_buffer *buf) {}
void load_file_pointer__0(object_write_buffer *buf) {}
 
void work_VSource__4_4__0(int ____n){
  for (
  ; (0 < ____n); (____n--)) {{
      // mark begin: SIRFilter VSource

      ((x__0__0) = ((x__0__0) + ((float)3.25)))/*float*/;
      __push_0_1((x__0__0));
      ((y__1__0) = ((y__1__0) + ((float)0.42)))/*float*/;
      __push_0_1((y__1__0));
      // mark end: SIRFilter VSource

    }
  }
}

// peek: 2 pop: 2 push 1
// init counts: 0 steady counts: 1

// ClusterFusion isEliminated: false



int __number_of_iterations_1;
int __counter_1 = 0;
int __steady_1 = 0;
int __tmp_1 = 0;
int __tmp2_1 = 0;
int *__state_flag_1 = NULL;
thread_info *__thread_1 = NULL;



void save_peek_buffer__1(object_write_buffer *buf);
void load_peek_buffer__1(object_write_buffer *buf);
void save_file_pointer__1(object_write_buffer *buf);
void load_file_pointer__1(object_write_buffer *buf);

inline void check_status__1() {
  check_thread_status(__state_flag_1, __thread_1);
}

void check_status_during_io__1() {
  check_thread_status_during_io(__state_flag_1, __thread_1);
}

void __init_thread_info_1(thread_info *info) {
  __state_flag_1 = info->get_state_flag();
}

thread_info *__get_thread_info_1() {
  if (__thread_1 != NULL) return __thread_1;
  __thread_1 = new thread_info(1, check_status_during_io__1);
  __init_thread_info_1(__thread_1);
  return __thread_1;
}

void __declare_sockets_1() {
  init_instance::add_incoming(0,1, DATA_SOCKET);
  init_instance::add_outgoing(1,2, DATA_SOCKET);
}

void __init_sockets_1(void (*cs_fptr)()) {
  mysocket *sock;

}

void __flush_sockets_1() {
}

void __peek_sockets_1() {
}

 
void init_Worker__10_5__1();
inline void check_status__1();

void work_Worker__10_5__1(int);


inline float __pop_0_1() {
float res=BUFFER_0_1[TAIL_0_1];
TAIL_0_1++;
return res;
}

inline void __pop_0_1(int n) {
TAIL_0_1+=n;
}

inline float __peek_0_1(int offs) {
return BUFFER_0_1[TAIL_0_1+offs];
}



inline void __push_1_2(float data) {
BUFFER_1_2[HEAD_1_2]=data;
HEAD_1_2++;
}



 
void init_Worker__10_5__1(){
}
void save_file_pointer__1(object_write_buffer *buf) {}
void load_file_pointer__1(object_write_buffer *buf) {}
 
void work_Worker__10_5__1(int ____n){
  for (
  ; (0 < ____n); (____n--)) {{
      float x__7 = 0.0f;/* float */
      float y__8 = 0.0f;/* float */
      float __tmp2__9 = 0.0f;/* float */

      // mark begin: SIRFilter Worker

      x__7 = BUFFER_0_1[TAIL_0_1]; TAIL_0_1++;
;
      y__8 = BUFFER_0_1[TAIL_0_1]; TAIL_0_1++;
;
      (__tmp2__9 = ((x__7 - y__8) * (x__7 - y__8)))/*float*/;
      __push_1_2(__tmp2__9);
      // mark end: SIRFilter Worker

    }
  }
}

// peek: 1 pop: 1 push 0
// init counts: 0 steady counts: 1

// ClusterFusion isEliminated: false



int __number_of_iterations_2;
int __counter_2 = 0;
int __steady_2 = 0;
int __tmp_2 = 0;
int __tmp2_2 = 0;
int *__state_flag_2 = NULL;
thread_info *__thread_2 = NULL;



void save_peek_buffer__2(object_write_buffer *buf);
void load_peek_buffer__2(object_write_buffer *buf);
void save_file_pointer__2(object_write_buffer *buf);
void load_file_pointer__2(object_write_buffer *buf);

inline void check_status__2() {
  check_thread_status(__state_flag_2, __thread_2);
}

void check_status_during_io__2() {
  check_thread_status_during_io(__state_flag_2, __thread_2);
}

void __init_thread_info_2(thread_info *info) {
  __state_flag_2 = info->get_state_flag();
}

thread_info *__get_thread_info_2() {
  if (__thread_2 != NULL) return __thread_2;
  __thread_2 = new thread_info(2, check_status_during_io__2);
  __init_thread_info_2(__thread_2);
  return __thread_2;
}

void __declare_sockets_2() {
  init_instance::add_incoming(1,2, DATA_SOCKET);
}

void __init_sockets_2(void (*cs_fptr)()) {
  mysocket *sock;

}

void __flush_sockets_2() {
}

void __peek_sockets_2() {
}

 
void init_FloatPopper__13_6__2();
inline void check_status__2();

void work_FloatPopper__13_6__2(int);


inline float __pop_1_2() {
float res=BUFFER_1_2[TAIL_1_2];
TAIL_1_2++;
return res;
}

inline void __pop_1_2(int n) {
TAIL_1_2+=n;
}

inline float __peek_1_2(int offs) {
return BUFFER_1_2[TAIL_1_2+offs];
}


 
void init_FloatPopper__13_6__2(){
}
void save_file_pointer__2(object_write_buffer *buf) {}
void load_file_pointer__2(object_write_buffer *buf) {}
 
void work_FloatPopper__13_6__2(int ____n){
  for (
  ; (0 < ____n); (____n--)) {{
      // mark begin: SIRFilter FloatPopper

      __pop_1_2();
      // mark end: SIRFilter FloatPopper

    }
  }
}

