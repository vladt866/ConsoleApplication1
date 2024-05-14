#include <iostream>
#include <fstream>
#include "vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    vector vctr;
    vctr.set_vector();
    cin >> vctr;
    cout << vctr;


    return 0;
}