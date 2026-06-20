#ifndef MODULE_COMPUTE
#define MODULE_COMPUTE
#include <cstdint>


bool prime_num(int n);
int mod_mul(int first, int second, int mod);
int ferma_modulo(int base, int power, int mod, int* new_power);
int64_t binary_modulo(int64_t base, int64_t power, int64_t mod);

#endif