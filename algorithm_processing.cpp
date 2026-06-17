#include <iostream>
#include <string>
#include "module_compute.h"
#include "el_gamal_compute.h"
#include "euclid_compute.h"

int modul_processing(){
    int a, x, p;
    std::cout << "Введите основание: " << std::endl;
    std::cin >> a;
    std::cout << "Введите степень: " << std::endl;
    std::cin >> x;
    std::cout << "Введите модуль: " << std::endl;
    std::cin >> p;
    int reduced_power = 0;

    if (ferma_modulo(a, x, p, &reduced_power) == -1){
        std::cout << "Не выполенены условия теоремы Ферма!" << std::endl;
        return -1;
    } else {
        std::cout << "Результат по Ферма: " << ferma_modulo(a, x, p, &reduced_power) << std::endl;
        std::cout << "Пониженная степень: " << reduced_power << std::endl;
        std::cout << "Результат бинарным методом: " << binary_modulo(a, x, p) << std::endl << std::endl;
        return 1;
    }
}

void euclid_processing(){
    int c, m;
    std::cout << "Введите число: ";
    std::cin >> c;
    std::cout << "Введите модуль: ";
    std::cin >> m;

    int u, v, gcd;
    reverse_num(c, m, u, v, gcd);
    
    if (gcd != 1){
        std::cout << "Ошибка: обратного числа не существует (НОД != 1)" << std::endl;
    } else {
        int inverse = u % m;
        if (inverse < 0) inverse += m;
        std::cout << "\nРезультат расширенного алгоритма Евклида:" << std::endl;
        std::cout << "Взаимообратное число = " << inverse << std::endl;
        std::cout << "Проверка: (" << c << " * " << inverse << ") mod " << m << " = " << (c * inverse) % m << std::endl;
    }
}

int el_gamal_processing() {
    int64_t p, g;
    std::string input, enc, dec;
    
    std::cout << "\nЭЛЬ-ГАМАЛЬ\n";
    std::cout << "Введите простое число P: ";
    std::cin >> p;
    std::cout << "Введите корень G: ";
    std::cin >> g;
    std::cout << "Введите имя входного файла: ";
    std::cin >> input;
    std::cout << "Введите имя зашифрованного файла: ";
    std::cin >> enc;
    std::cout << "Введите имя расшифрованного файла: ";
    std::cin >> dec;
    
    elgamal(p, g, input, enc, dec);
    return 0;
}