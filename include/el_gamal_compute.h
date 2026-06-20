#ifndef EL_GAMAL_COMPUTE_H
#define EL_GAMAL_COMPUTE_H
#include <cstdint>
#include <string>

int elgamal(int64_t p, int64_t g, const std::string& input_filename, 
             const std::string& encrypted_filename, const std::string& decrypted_filename);

#endif