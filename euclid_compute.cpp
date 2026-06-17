#include <iostream>
#include <iomanip>

void reverse_num(int c, int m, int& u, int& v, int& gcd) {
    int u0 = 1, u1 = 0;
    int v0 = 0, v1 = 1;
    int step = 1;

    int q, r, temp;

    std::cout << "Расширенный алгоритм Евклида:" << std::endl;
    std::cout << std::setw(6) << "Шаг" << std::setw(8) << "c" << std::setw(8) << "m" << std::setw(8) << "q" << std::setw(8) << "r" << std::setw(8) << "u" << std::setw(8) << "v" << std::endl;

    while (m != 0) {
        q = c / m;
        r = c % m;
        
        std::cout << std::setw(2) << step++ << std::setw(9) << c << std::setw(9) << m << std::setw(7) << q << std::setw(8) << r << std::setw(8) << u0 << std::setw(8) << v0 << std::endl;
        
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
    std::cout << std::setw(2) << step << std::setw(9) << c << std::setw(9) << m << std::setw(7) << "-" << std::setw(8) << "-" << std::setw(8) << u0 << std::setw(8) << v0 << std::endl << std::endl;
    
    gcd = c;
    u = u0;
    v = v0;
}