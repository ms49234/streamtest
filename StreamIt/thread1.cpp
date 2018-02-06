// peek: 2 pop: 2 push 1
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
message *__msg_stack_1;
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

extern float BUFFER_0_1[];
extern int HEAD_0_1;
extern int TAIL_0_1;

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

extern float BUFFER_1_2[];
extern int HEAD_1_2;
extern int TAIL_1_2;


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

