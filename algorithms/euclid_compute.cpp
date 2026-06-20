#include "../include/euclid_compute.h"
#include <iostream>
#include <iomanip>
#include <vector>


std::ostream& operator<<(std::ostream& os, std::vector<Step>& steps){
    os << "Расширенный алгоритм Евклида:" << std::endl;
    os << std::setw(6) << "Шаг" << std::setw(8) << "c" << std::setw(8) << "m" << std::setw(8) << "q" << std::setw(8) << "r" << std::setw(8) << "u" << std::setw(8) << "v" << std::endl;
    for (const auto& s : steps) {
        if (s.q == -1 && s.r == -1) {
            os << std::setw(2) << s.step << std::setw(9) << s.c << std::setw(9) << s.m << std::setw(7) << "-" << std::setw(8) << "-" << std::setw(8) << s.u << std::setw(8) << s.v << std::endl;
        } else {
            os << std::setw(2) << s.step << std::setw(9) << s.c << std::setw(9) << s.m << std::setw(7) << s.q << std::setw(8) << s.r << std::setw(8) << s.u << std::setw(8) << s.v << std::endl;
        }
    }    
    return os;
}


std::vector<Step> reverse_num(int c, int m, int& gcd) {
    int u0 = 1, u1 = 0;
    int v0 = 0, v1 = 1;
    int step = 1;

    int q, r, temp;
    std::vector<Step> steps;

    while (m != 0) {
        q = c / m;
        r = c % m;
        
        steps.push_back({++step, c, m, q, u0, v0});
        
        temp = m;
        m = r;
        c = temp;

        temp = u1;
        u1 = u0 - q * u1;
        u0 = temp;

        temp = v1;
        v1 = v0 - q * v1;
        v0 = temp;
    }
    gcd = c;
    steps.push_back({step, c, m, -1, -1, u0, v0});
    
    return steps;
}