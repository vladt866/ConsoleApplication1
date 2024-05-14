#pragma once
#pragma once

#include <iostream>
#include <cmath>
#include<algorithm>
#include <ctime>

using namespace std;

class vector {
private:
    int size;
    int* vctr;

public:
    vector();
    vector(int size);
    vector(const vector& other);
    ~vector();

    void set_vector();
    int get_size();
    int get_element(int index);
    void set_element(int index, int number);
    void scalar();
    void length();
    void vectors(vector& vctr1, vector& vctr2);
    void get_all_elements();
    void set_all_elements();
    void random_elements_of_vector();
    void task(vector& vctr1, vector& vctr2);
    vector& operator=(const vector& vctr1);

    // Прототипы методов
    //friend ostream& operator<<(ostream& os, const vector& vec);
   //friend istream& operator>>(istream& is, vector& vec);



    //прототипы функции
    friend ostream& operator<<(ostream& os, const vector& vector);
    friend istream& operator>>(istream& is, vector& vector);


    //// Перегрузка оператора вывода как метод класса
    //ostream& operator<<(ostream& os) const;

    //// Перегрузка оператора ввода как метод класса
    //istream& operator>>(istream& is);

};

