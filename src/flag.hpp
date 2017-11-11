#pragma once

const static uint32_t flag_len = 56;
const static uint32_t table_nlen = flag_len / 4;

// Parameters for CUDA
const static uint32_t table_block_width = 32;
const static uint32_t table_size = table_block_width * table_block_width;

#ifndef SOLVE_FLAG
#include "flag_table.hpp"
#else
const static char right_flag[]="cuda_15_fun_bu7_d0_u_kn0w_h0w_to_make_FUN_by_it_nowadays";
#endif
