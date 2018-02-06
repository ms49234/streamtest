#ifndef _SG_VectorDist_GLOBALS_H
#define _SG_VectorDist_GLOBALS_H

#include "barrier.h"
#include "structs.h"
#include <stdint.h>

using namespace _smpsg_internal;

#define ITERATIONS -1

#define minf(a, b) ((a) < (b) ? (a) : (b))
#define maxf(a, b) ((a) > (b) ? (a) : (b))

// Global barrier
extern barrier_t barrier;

// Shared buffers
extern float __chan__0___Buf_0[16];
extern float __chan__0___Buf_1[16];
extern float __chan__2___Buf_0[8];
extern float __chan__2___Buf_1[8];
extern float *__sgate_memr_buff_in_buff;
extern unsigned int __sgate_memr_size_in_buff;
extern unsigned int __sgate_memr_iter_in_buff;
extern unsigned int __sgate_memr_tcon_in_buff;
extern bool __sgate_memr_loop_in_buff;
extern int __sgate_memr_itlc_in_buff_0;
extern float *__sgate_memw_buff_out_buff;
extern unsigned int __sgate_memw_size_out_buff;
extern unsigned int __sgate_memw_iter_out_buff;
extern unsigned int __sgate_memw_tcon_out_buff;
extern bool __sgate_memw_loop_out_buff;

// CPU Affinity
extern void setCPUAffinity(int core);

// Thread entry points
extern void *__main____4(void * arg);
extern void *__main____13(void * arg);
extern void *__main____15(void * arg);
extern void *__main____17(void * arg);

#endif
