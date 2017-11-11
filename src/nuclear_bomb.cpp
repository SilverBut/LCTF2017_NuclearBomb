#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "flag.hpp"
#include "mt19937.hpp"
#include "nuclear_core.hpp"

#ifdef SOLVE_FLAG
#include <fstream>
#endif

#define err_pwdlen() throw std::logic_error("Wrong password length.")

int main(void) {

#ifndef SOLVE_FLAG
  std::string password;
  std::cout << "You need to enter a password to enable this BIG RED button."
            << std::endl;
  std::cout << "Password (will BE shown): ";
  std::cin >> password;
#else
  std::string password;
  password = right_flag;
#endif

  // The passwords should be divided by 4,
  // and should be able to divide flag_target
  if (password.length() != flag_len) {
    err_pwdlen();
  };
  if (password.length() % 4) {
    err_pwdlen();
  };

  // Init and generate random stream
  const uint32_t *pwd_int32 = (uint32_t *)password.c_str();
  // Build a xor stream
  uint32_t *xor_stream = new uint32_t[table_size * table_nlen];
  const uint8_t *xor_stream_char = (uint8_t *)xor_stream;
  for (size_t i = 0; i < table_nlen; i++) {
    mtrand r(pwd_int32[i]);
    for (size_t j = 0; j < table_size; j++) {
      xor_stream[j * table_nlen + i] = r.rand();
    };
  };

  do_bomb(xor_stream);

#ifndef SOLVE_FLAG
  std::cout << "Ummmm, let POTUS see..." << std::endl;
  for (size_t i = 0; i < table_size * table_nlen; i++) {
    assert(xor_stream[i] == table[i]);
  }
  std::cout << "Seems right. Submit what youve input." << std::endl;
#else
  std::cout << "\
#pragma once\n\
#include \"flag.hpp\"\n\
" << std::endl;
  std::cout << "const static uint32_t table[table_size * table_nlen] = {"
            << std::endl;
  for (size_t i = 0; i < table_size * table_nlen - 1; i++) {
    std::cout << xor_stream[i] << ", ";
  }
  std::cout << xor_stream[table_size * table_nlen - 1];
  std::cout << "};";
#endif
  return 0;
}
