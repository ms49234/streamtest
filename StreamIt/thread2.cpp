// peek: 1 pop: 1 push 0
// init counts: 0 steady counts: 1

// ClusterFusion isEliminated: false

#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <init_instance.h>
#include <mysocket.h>
#include <object_write_buffer.h>
#include <save_state.h>
#include <sdep.h>
#include <message.h>
#include <timer.h>
#include <thread_info.h>
#include <consumer2.h>
#include <consumer2p.h>
#include <producer2.h>
#include "cluster.h"
#include "fusion.h"
#include "global.h"

extern int __max_iteration;
extern int __init_iter;
extern int __timer_enabled;
extern int __frequency_of_chkpts;
extern volatile int __vol;
message *__msg_stack_2;
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

extern float BUFFER_1_2[];
extern int HEAD_1_2;
extern int TAIL_1_2;

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

