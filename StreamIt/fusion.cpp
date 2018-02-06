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
extern void init_VSource__4_4__0();
extern void work_VSource__4_4__0(int);
extern void init_Worker__10_5__1();
extern void work_Worker__10_5__1(int);
extern void init_FloatPopper__13_6__2();
extern void work_FloatPopper__13_6__2(int);

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
