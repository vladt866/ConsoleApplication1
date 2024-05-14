#include "vector.h"


vector::vector() {
    size = 0;
    vctr = nullptr;
}

vector::vector(int size) {
    this->size = size;
    vctr = new int[size];
}

vector::vector(const vector& other) {
    size = other.size;
    vctr = new int[size];
    for (int i = 0; i < size; i++) {
        vctr[i] = other.vctr[i];
    }
}

vector::~vector() {
    delete[] vctr;
}

void vector::set_vector() {
    cout << "Введите размер вектора: ";
    cin >> size;
    vctr = new int[size];
    cout << endl;
}

int vector::get_size() {
    return size;
    cout << endl;
}

int vector::get_element(int index) {
    if (index >= size) {
        cout << "Вы вышли за пределы размерности вектора." << endl;
        return 0;
    }

    return vctr[index];
    cout << endl;
}

void vector::set_element(int index, int number) {
    if (index < size) {
        vctr[index] = number;
        cout << endl;
    }
    else {
        cout << "Вы вышли за пределы размерности вектора." << endl;
    }
}

void vector::scalar() {
    cout << "Введите номер операции, которую вы хотите провести со скаляром:\n1.Сложение\n2.Вычитание\n3.Умножение\n4.Деление" << endl << endl;
    int choice;
    cin >> choice;
    cout << "Введите значение скаляра: ";
    int scalar;
    cin >> scalar;
    cout << endl;
    switch (choice) {
    case 1:
        for (int i = 0; i < size; i++) {
            vctr[i] += scalar;
            cout << vctr[i] << " ";
        }
        break;
    case 2:
        for (int i = 0; i < size; i++) {
            vctr[i] -= scalar;
            cout << vctr[i] << " ";
        }
        break;
    case 3:
        for (int i = 0; i < size; i++) {
            vctr[i] *= scalar;
            cout << vctr[i] << " ";
        }
        break;
    case 4:
        for (int i = 0; i < size; i++) {
            if (scalar != 0) {
                vctr[i] = static_cast<double>(vctr[i]) / scalar;
                cout << vctr[i] << " ";
            }
            else {
                cout << "Ошибка: деление на ноль." << endl;
                break;
            }
        }
        break;
    }
}

void vector::length() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vctr[i] * vctr[i];
    }
    double length = sqrt(sum);
    cout << "Длина вектора: " << length << endl;
}

void vector::vectors(vector& vctr1, vector& vctr2) {
    if (size != vctr1.size && size != vctr2.size) {
        cout << "Векторы имеют разные размеры." << endl;
        return;
    }

    cout << "Введите операцию, которую вы хотите провести с векторами:\n\n1.Сложение\n2.Вычитание\n3.Умножение\n4.Деление" << endl << endl;
    int choice;
    cin >> choice;
    cout << endl;
    switch (choice) {
    case 1:
        for (int i = 0; i < size; i++) {
            vctr[i] = vctr1.vctr[i] + vctr2.vctr[i];
            cout << vctr[i] << " ";
        }
        break;
    case 2:
        for (int i = 0; i < size; i++) {
            vctr[i] = vctr1.vctr[i] - vctr2.vctr[i];
            cout << vctr[i] << " ";
        }
        break;
    case 3:
        for (int i = 0; i < size; i++) {
            vctr[i] = vctr1.vctr[i] * vctr2.vctr[i];
            cout << vctr[i] << " ";
        }
        break;
    case 4:
        for (int i = 0; i < size; i++) {
            if (vctr2.vctr[i] != 0) {
                vctr[i] = static_cast<double>(vctr1.vctr[i]) / vctr2.vctr[i];
                cout << vctr[i] << " ";
            }
            else {
                cout << "Ошибка: деление на ноль." << endl;
                break;
            }
        }
        break;
    }
}

void vector::get_all_elements() {
    cout << "Значения всех элементов вектора: ";
    for (int i = 0; i < size; i++) {
        cout << vctr[i] << " ";
    }
    cout << endl << endl;
}

void vector::set_all_elements() {
    cout << "Введите элементы вектора: ";
    for (int i = 0; i < size; i++) {
        cin >> vctr[i];
    }
    cout << endl;
}

void vector::random_elements_of_vector() {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vctr[i] = rand() % 21 - 10;
    }
}

void vector::task(vector& vctr1, vector& vctr2) {
    if (vctr1.size != vctr2.size) {
        cout << "Векторы имеют разные размеры." << endl;
        return;
    }

    size = vctr1.size;
    this->vctr = new int[size];


    int* sortedX = new int[size];
    copy(vctr1.vctr, vctr1.vctr + size, sortedX);
    sort(sortedX, sortedX + size);


    copy(sortedX, sortedX + size, vctr);


    int scalarProduct = 0;
    for (int i = 0; i < size; i++) {
        scalarProduct += vctr1.vctr[i] * vctr[i];
    }


    cout << "Полученный вектор Y (упорядоченный по возрастанию значений элементов X): ";
    for (int i = 0; i < size; i++) {
        cout << vctr[i] << " ";
    }

    cout << endl << "Скалярное произведение векторов X и Y: " << scalarProduct << endl << endl;

    delete[] sortedX;
}

vector& vector::operator=(const vector& vector)
{
    if (this != &vector)
    {
        if (size != vector.size)
        {
            delete[] this->vctr;
            size = vector.size;
            this->vctr = new int[size];
        }
        for (int i = 0; i < size; ++i)
            this->vctr[i] = vector.vctr[i];
    }
    return *this;
}



//istream& operator>>(istream& is, vector& vec) {
//    cout << "Элементы вектора: ";
//    for (int i = 0; i < vec.size; i++) {
//        is >> vec.vctr[i];
//    }
//    return is;
//}
//ostream& operator<<(ostream& os, const vector& vec) {
//    os << "Введите элементы вектора: ";
//    for (int i = 0; i < vec.size; i++) {
//        os << vec.vctr[i] << " ";
//    }
//    os << endl;
//    return os;
//}





ostream& operator<<(ostream& os, const vector& vector) {                      // функция
    os << "Введите элементы вектора: ";
    for (int i = 0; i < vector.size; i++) {
        os << vector.vctr[i] << " ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& is, vector& vector) {
    cout << "Элементы вектора: ";
    for (int i = 0; i < vector.size; i++) {
        is >> vector.vctr[i];
    }
    return is;
}

//// Перегрузка оператора вывода
//// Перегрузка оператора вывода как метод класса
//ostream& vector::operator<<(ostream& os) const {
//    os << "[ ";
//    for (int i = 0; i < size; i++) {
//        os << vctr[i] << " ";
//    }
//    os << "]";
//    return os;
//}
//
//// Перегрузка оператора ввода как метод класса
//istream& vector::operator>>(istream& is) {
//    int temp;
//    cout << "Enter vector size: ";
//    is >> size;
//    delete[] vctr;
//    vctr = new int[size];
//    cout << "Enter vector elements: ";
//    for (int i = 0; i < size; i++) {
//        is >> temp;
//        vctr[i] = temp;
//    }
//    return is;
//}