#include <iostream>

bool prime_num(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {return false;}
    }
    return true;  
}

int mod_mul(int first, int second, int mod) {
    int result = 0;          
    first = first % mod; 
    
    while (second > 0) {
        if (second % 2 == 1) {    
            result = (result + first) % mod;  
        }
        first = (first * 2) % mod;  
        second = second / 2;        
    }
    return result;
}


int ferma_modulo(int base, int power, int mod, int* new_power) {
    if (!prime_num(mod)) return -1;      
    if (base % mod == 0) return -1;        
    *new_power = power % (mod - 1);   
    if (*new_power == 0) return 1;
    int result = 1;
    for (int i = 0; i < *new_power; ++i) {result = mod_mul(result, base, mod);}
    return result;
}


int binary_modulo(int base, int power, int mod) {
    base = base % mod;  
    if (base == 0 && power > 0) return -1;
    
    int result = 1;
    
    while (power > 0) {
        if (power & 1) {                    
            result = mod_mul(result, base, mod);
        }
        base = mod_mul(base, base, mod);      
        power = power / 2;                  
    }
    return result;
}