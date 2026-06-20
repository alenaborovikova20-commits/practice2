#include "../include/module_compute.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static int64_t mod_inv(int64_t a, int64_t m) {
    int64_t m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int64_t q = a / m;
        int64_t t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

int elgamal(int64_t p, int64_t g, const string& input_filename, 
             const string& encrypted_filename, const string& decrypted_filename) {      
    srand(time(nullptr));
    
    int64_t x = rand() % (p - 2) + 2;
    int64_t y = binary_modulo(g, x, p);
    
    cout << "\nЭЛЬ-ГАМАЛЬ\n";
    cout << "Секретный ключ x = " << x << endl;
    cout << "Открытый ключ y = " << y << "\n\n";
    
    ifstream in(input_filename, ios::binary);
    if (!in) {
        cout << "Ошибка: не удалось открыть файл " << input_filename << endl;
        return -1;
    }
    vector<unsigned char> data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();
    cout << "Прочитано " << data.size() << " байт\n";
    
    ofstream enc(encrypted_filename, ios::binary);
    if (!enc) {
        cout << "Ошибка: не удалось создать файл " << encrypted_filename << endl;
        return -1;
    }
    
    cout << "Шифрование...\n";
    vector<pair<int64_t, int64_t>> blocks;
    
    for (unsigned char byte : data) {
        int64_t m = byte;
        int64_t k = rand() % (p - 2) + 1;
        int64_t a = binary_modulo(g, k, p);
        int64_t b = (m * binary_modulo(y, k, p)) % p;
        
        blocks.push_back({a, b});
        enc.write((char*)&a, sizeof(int64_t));
        enc.write((char*)&b, sizeof(int64_t));
    }
    enc.close();
    cout << "Зашифровано и сохранено в " << encrypted_filename << "\n";
    
    ofstream dec(decrypted_filename, ios::binary);
    if (!dec) {
        cout << "Ошибка: не удалось создать файл " << decrypted_filename << endl;
        return -1;
    }
    
    cout << "Расшифрование...\n";
    for (auto& block : blocks) {
        int64_t ax = binary_modulo(block.first, x, p);
        int64_t m = (block.second * mod_inv(ax, p)) % p;
        dec.put((unsigned char)m);
    }
    dec.close();
    cout << "Расшифровано и сохранено в " << decrypted_filename << "\n\n";
    return 1;
}