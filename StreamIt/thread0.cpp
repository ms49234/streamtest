// peek: 0 pop: 0 push 2
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
message *__msg_stack_0;
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

extern float BUFFER_0_1[];
extern int HEAD_0_1;
extern int TAIL_0_1;


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

