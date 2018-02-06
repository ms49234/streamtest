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


// code for core 0
float __chan__0___Buf_0[16];
float __chan__0___Buf_1[16];
__rotating_buffer_float *__chan__0__read_rot_struct;
__rotating_buffer_float *__chan__0___read_current;
float *__chan__0___read_buf;
__rotating_buffer_float *__chan__0___mr_current;
float *__chan__0___mr_buf;
float __chan__2___Buf_0[8];
float __chan__2___Buf_1[8];
__rotating_buffer_float *__chan__2__read_rot_struct;
__rotating_buffer_float *__chan__2___read_current;
float *__chan__2___read_buf;
__rotating_buffer_float *__chan__2___addr_0_rot_struct__;
__rotating_buffer_float *__chan__2___addr_0_write_current__;
float *__chan__2___addr_0__write_buf__;
float *__sgate_memr_buff_in_buff = NULL;
unsigned int __sgate_memr_size_in_buff = 0;
unsigned int __sgate_memr_iter_in_buff = 0;
unsigned int __sgate_memr_tcon_in_buff = 0;
bool __sgate_memr_loop_in_buff = false;
int __sgate_memr_itlc_in_buff_0 = 0;
float *__sgate_memw_buff_out_buff = NULL;
unsigned int __sgate_memw_size_out_buff = 0;
unsigned int __sgate_memw_iter_out_buff = 0;
unsigned int __sgate_memw_tcon_out_buff = 0;
bool __sgate_memw_loop_out_buff = false;


void __PRIMEPUMP__0__0();
void __Memory_Reader_PrimePump__0_in_buff____1();
void __INITSTAGE__0__2();
void __Memory_Reader_Init__0_in_buff____3();
void * __main____4(void * arg__9);
void init__4__5();

#ifndef __chan__4___CHANNEL_DATA
#define __chan__4___CHANNEL_DATA
#endif
#ifndef __chan__0___CHANNEL_DATA
#define __chan__0___CHANNEL_DATA
#endif
/* output buffer (__chan__4__ of Worker__7_5) */
static int __chan__4__head;


static inline void __push_4(float __val) {
  (((__chan__2___addr_0__write_buf__)[(int)((__chan__4__head)++)]) = __val);
}
/* input buffer (__chan__0__ of Worker__7_5) */
static int __chan__0__tail;


static inline float __peek_0(int __offset) {
  return ((__chan__0___read_buf)[(int)((__chan__0__tail) + __offset)]);
}


static inline void __peekv_0(int __val, int __offset) {
  /* assignFromPeekMethod not yet implemented */;
}


static inline float __pop_0() {
  return ((__chan__0___read_buf)[(int)((__chan__0__tail)++)]);
}


static inline void __popv_0(int __val) {
  /* assignFromPopMethod not yet implemented */;
}


void __popN_0(int n) {
  {
    int i = 0;
    for ((i = 0); (i < n); (i++)) {
      __pop_0();
    }
  }
}




void buffer_and_address_init__n0() {
  {
    __rotating_buffer_float *__temp__;
    __chan__0__read_rot_struct =  (__rotating_buffer_float*)malloc(sizeof(__rotating_buffer_float));
    __chan__0__read_rot_struct->buffer = __chan__0___Buf_0;
    __temp__ = (__rotating_buffer_float*)malloc(sizeof(__rotating_buffer_float));
    __chan__0__read_rot_struct->next = __temp__;
    __temp__->buffer = __chan__0___Buf_1;
    __temp__->next = __chan__0__read_rot_struct;
    __chan__0___read_current = __chan__0__read_rot_struct;
    __chan__0___read_buf = __chan__0___read_current->buffer;
    __chan__0___mr_current = __chan__0__read_rot_struct;
    __chan__0___mr_buf = __chan__0___read_current->buffer;
  }
  {
    __rotating_buffer_float *__temp__;
    __chan__2__read_rot_struct =  (__rotating_buffer_float*)malloc(sizeof(__rotating_buffer_float));
    __chan__2__read_rot_struct->buffer = __chan__2___Buf_0;
    __temp__ = (__rotating_buffer_float*)malloc(sizeof(__rotating_buffer_float));
    __chan__2__read_rot_struct->next = __temp__;
    __temp__->buffer = __chan__2___Buf_1;
    __temp__->next = __chan__2__read_rot_struct;
    __chan__2___read_current = __chan__2__read_rot_struct;
    __chan__2___read_buf = __chan__2___read_current->buffer;
  }
  barrier.wait();
  float* __chan__2___addr_0__Buf_0;
  float* __chan__2___addr_0__Buf_1;
  __chan__2___addr_0__Buf_0 = __chan__2___Buf_0;
  __chan__2___addr_0__Buf_1 = __chan__2___Buf_1;
  {
    __rotating_buffer_float *__temp__;
    __chan__2___addr_0_rot_struct__ =  (__rotating_buffer_float*)malloc(sizeof(__rotating_buffer_float));
    __chan__2___addr_0_rot_struct__->buffer = __chan__2___addr_0__Buf_0;
    __temp__ = (__rotating_buffer_float*)malloc(sizeof(__rotating_buffer_float));
    __chan__2___addr_0_rot_struct__->next = __temp__;
    __temp__->buffer = __chan__2___addr_0__Buf_1;
    __temp__->next = __chan__2___addr_0_rot_struct__;
    __chan__2___addr_0_write_current__ = __chan__2___addr_0_rot_struct__;
    __chan__2___addr_0__write_buf__ = __chan__2___addr_0_write_current__->buffer;
  }
}


void __PRIMEPUMP__0__0() {
  int __WORKCOUNTER____6 = 0;
  float x__5__7 = 0.0f;
  float y__6__8 = 0.0f;
  ((__chan__0__tail) = 0);
  ((__chan__4__head) = 0);
  for ((__WORKCOUNTER____6 = 0); (__WORKCOUNTER____6 < 8); (__WORKCOUNTER____6++)) {
    {
      // mark begin: filter Worker__7_5.work__3

      (x__5__7 = __pop_0());
      (y__6__8 = __pop_0());
      __push_4(((x__5__7 - y__6__8) * (x__5__7 - y__6__8)));
      // mark end: filter Worker__7_5.work__3

    }
  }
  __chan__0___read_current = __chan__0___read_current->next;
  __chan__0___read_buf = __chan__0___read_current->buffer;
  __chan__2___addr_0_write_current__ = __chan__2___addr_0_write_current__->next;
  __chan__2___addr_0__write_buf__ = __chan__2___addr_0_write_current__->buffer;
}


void __Memory_Reader_PrimePump__0_in_buff____1() {
  	while (__sgate_memr_itlc_in_buff_0 + 16 > __sgate_memr_size_in_buff) {
		if (__sgate_memr_loop_in_buff) __sgate_memr_itlc_in_buff_0 = 0;
		else barrier.wait_block();
	}
;
  for (int __ias__ = 0; __ias__ < 16; __ias__++) __chan__0___mr_buf[0 + __ias__] = __sgate_memr_buff_in_buff[__sgate_memr_itlc_in_buff_0 + 0 + __ias__];
  __chan__0___mr_current = __chan__0___mr_current->next;
  __chan__0___mr_buf = __chan__0___mr_current->buffer;
  __sgate_memr_itlc_in_buff_0 += 16;
  __sgate_memr_iter_in_buff += 16;
  __sgate_memr_tcon_in_buff += 16;
}


void __INITSTAGE__0__2() {
  ((__chan__0__tail) = 0);
  /* Barrier before write */;
  barrier.wait();
}


void __Memory_Reader_Init__0_in_buff____3() {
  	while (__sgate_memr_itlc_in_buff_0 + 0 > __sgate_memr_size_in_buff) {
		if (__sgate_memr_loop_in_buff) __sgate_memr_itlc_in_buff_0 = 0;
		else barrier.wait_block();
	}
;
  __sgate_memr_itlc_in_buff_0 += 0;
  __sgate_memr_iter_in_buff += 0;
  __sgate_memr_tcon_in_buff += 0;
}


void * __main____4(void * arg__9) {
  int __WORKCOUNTER____10 = 0;
  float x__5__11 = 0.0f;
  float y__6__12 = 0.0f;
  setCPUAffinity(0);
  buffer_and_address_init__n0();
  barrier.wait_block();
  init__4__5();
  __Memory_Reader_Init__0_in_buff____3();
  __INITSTAGE__0__2();
  __Memory_Reader_PrimePump__0_in_buff____1();
  __Memory_Reader_PrimePump__0_in_buff____1();
  __PRIMEPUMP__0__0();

  while (1) {
    	while (__sgate_memr_itlc_in_buff_0 + 16 > __sgate_memr_size_in_buff) {
		if (__sgate_memr_loop_in_buff) __sgate_memr_itlc_in_buff_0 = 0;
		else barrier.wait_block();
	}
;
    for (int __ias__ = 0; __ias__ < 16; __ias__++) __chan__0___mr_buf[0 + __ias__] = __sgate_memr_buff_in_buff[__sgate_memr_itlc_in_buff_0 + 0 + __ias__];
    __chan__0___mr_current = __chan__0___mr_current->next;
    __chan__0___mr_buf = __chan__0___mr_current->buffer;
    __sgate_memr_itlc_in_buff_0 += 16;
    __sgate_memr_iter_in_buff += 16;
    __sgate_memr_tcon_in_buff += 16;
    ((__chan__0__tail) = 0);
    ((__chan__4__head) = 0);
    for ((__WORKCOUNTER____10 = 0); (__WORKCOUNTER____10 < 8); (__WORKCOUNTER____10++)) {
      {
        // mark begin: filter Worker__7_5.work__3

        (x__5__11 = __pop_0());
        (y__6__12 = __pop_0());
        __push_4(((x__5__11 - y__6__12) * (x__5__11 - y__6__12)));
        // mark end: filter Worker__7_5.work__3

      }
    }
    __chan__0___read_current = __chan__0___read_current->next;
    __chan__0___read_buf = __chan__0___read_current->buffer;
    __chan__2___addr_0_write_current__ = __chan__2___addr_0_write_current__->next;
    __chan__2___addr_0__write_buf__ = __chan__2___addr_0_write_current__->buffer;
    /* Steady-State Barrier */;
    barrier.wait();
    	while (__sgate_memw_iter_out_buff + 8 > __sgate_memw_size_out_buff) {
		if (__sgate_memw_loop_out_buff) __sgate_memw_iter_out_buff = 0;
		else barrier.wait_block();
	}
	memcpy(__sgate_memw_buff_out_buff + __sgate_memw_iter_out_buff, __chan__2___addr_0__write_buf__, 8 * sizeof(float));
	__sgate_memw_iter_out_buff += 8;
	__sgate_memw_tcon_out_buff += 8;;
    /* Steady-State Barrier */;
    barrier.wait();
  }
  pthread_exit(NULL);
}


void init__4__5() {
  // mark begin: filter Worker__7_5.init__4

  // mark end: filter Worker__7_5.init__4

}
