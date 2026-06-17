#include <iostream>
#include "algorithm_processing.h"
using namespace std;

enum choices{
    MODUL = 1,
    EUCLID = 2,
    EL_GAMAL = 3
};

int main(){
    cout << "1 - Возведение в степень" << endl;
    cout << "2 - Алгоритмы Евклида" << endl;
    cout << "3 - Алгоритм шифрования Эль-Гамаля" << endl;
    
    int choice;
    cout << "\nВведите номер задания: "; 
    cin >> choice;
    
    switch(choice){
        case MODUL: 
            modul_processing();
            break;
        case EUCLID:
            euclid_processing();
            break;
        case EL_GAMAL:
            el_gamal_processing();
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
    }
    
    return 0;
}