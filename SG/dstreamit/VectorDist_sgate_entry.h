#ifndef _SG_VectorDist_SGATE_ENTRY_H
#define _SG_VectorDist_SGATE_ENTRY_H

/* StreamIt structure types visible through memory r/w */
#include "VectorDist_structs_exposed.h"

/* StreamGate interface */

// SYNC BEFORE FIRE; FIRE DESYNCS
int VectorDist_sgate_fire();
// Sync function
int VectorDist_sgate_synchronize();
// Syncs before returning; CALL ONCE - FIRST
int VectorDist_sgate_init();
// Syncs before exiting; CALL ONCE - LAST; NO REINIT
int VectorDist_sgate_exit();

// SYNC BEFORE READER ASSIGNS / CHANGES
int VectorDist_sgate_assign_memr_in_buff(float *buffer, unsigned int size);
int VectorDist_sgate_get_index_memr_in_buff();
int VectorDist_sgate_get_tcon_memr_in_buff();
int VectorDist_sgate_set_loop_memr_in_buff(bool loop);
extern const int VectorDist_sgate_min_size_memr_in_buff;

// SYNC BEFORE WRITER ASSIGNS / CHANGES
int VectorDist_sgate_assign_memw_out_buff(float *buffer, unsigned int size);
int VectorDist_sgate_get_index_memw_out_buff();
int VectorDist_sgate_get_tcon_memw_out_buff();
int VectorDist_sgate_set_loop_memw_out_buff(bool loop);
extern const int VectorDist_sgate_min_size_memw_out_buff;

/* StreamGate interface end */

#endif
