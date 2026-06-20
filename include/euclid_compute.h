#ifndef EUCLID_COMPUTE
#define EUCLID_COMPUTE
#include <vector>
#include <iostream>

struct Step {
    int step;
    int c;
    int m;
    int q;
    int r;
    int u;
    int v;
};

std::ostream& operator<<(std::ostream& os, std::vector<Step>& steps);
std::vector<Step> reverse_num(int c, int m, int& gcd);

#endif