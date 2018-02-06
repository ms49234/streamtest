#ifndef _SG_VectorDist_STRUCTS_H
#define _SG_VectorDist_STRUCTS_H

typedef int bit;
typedef unsigned char byte;
typedef struct __Complex {
	float real;
	float imag;
} Complex;
typedef struct __float2 {
	float x;
	float y;
} float2;
typedef struct __float3 {
	float x;
	float y;
	float z;
} float3;
typedef struct __float4 {
	float x;
	float y;
	float z;
	float w;
} float4;
typedef struct __rotating_struct_float__ *__rot_ptr_float__;
typedef struct __rotating_struct_float__ {
	float *buffer;
	__rot_ptr_float__ next;
} __rotating_buffer_float;

#endif
