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
    cout << "������� ������ �������: ";
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
        cout << "�� ����� �� ������� ����������� �������." << endl;
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
        cout << "�� ����� �� ������� ����������� �������." << endl;
    }
}

void vector::scalar() {
    cout << "������� ����� ��������, ������� �� ������ �������� �� ��������:\n1.��������\n2.���������\n3.���������\n4.�������" << endl << endl;
    int choice;
    cin >> choice;
    cout << "������� �������� �������: ";
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
                cout << "������: ������� �� ����." << endl;
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
    cout << "����� �������: " << length << endl;
}

void vector::vectors(vector& vctr1, vector& vctr2) {
    if (size != vctr1.size && size != vctr2.size) {
        cout << "������� ����� ������ �������." << endl;
        return;
    }

    cout << "������� ��������, ������� �� ������ �������� � ���������:\n\n1.��������\n2.���������\n3.���������\n4.�������" << endl << endl;
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
                cout << "������: ������� �� ����." << endl;
                break;
            }
        }
        break;
    }
}

void vector::get_all_elements() {
    cout << "�������� ���� ��������� �������: ";
    for (int i = 0; i < size; i++) {
        cout << vctr[i] << " ";
    }
    cout << endl << endl;
}

void vector::set_all_elements() {
    cout << "������� �������� �������: ";
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
        cout << "������� ����� ������ �������." << endl;
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


    cout << "���������� ������ Y (������������� �� ����������� �������� ��������� X): ";
    for (int i = 0; i < size; i++) {
        cout << vctr[i] << " ";
    }

    cout << endl << "��������� ������������ �������� X � Y: " << scalarProduct << endl << endl;

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
//    cout << "�������� �������: ";
//    for (int i = 0; i < vec.size; i++) {
//        is >> vec.vctr[i];
//    }
//    return is;
//}
//ostream& operator<<(ostream& os, const vector& vec) {
//    os << "������� �������� �������: ";
//    for (int i = 0; i < vec.size; i++) {
//        os << vec.vctr[i] << " ";
//    }
//    os << endl;
//    return os;
//}





ostream& operator<<(ostream& os, const vector& vector) {                      // �������
    os << "������� �������� �������: ";
    for (int i = 0; i < vector.size; i++) {
        os << vector.vctr[i] << " ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& is, vector& vector) {
    cout << "�������� �������: ";
    for (int i = 0; i < vector.size; i++) {
        is >> vector.vctr[i];
    }
    return is;
}

//// ���������� ��������� ������
//// ���������� ��������� ������ ��� ����� ������
//ostream& vector::operator<<(ostream& os) const {
//    os << "[ ";
//    for (int i = 0; i < size; i++) {
//        os << vctr[i] << " ";
//    }
//    os << "]";
//    return os;
//}
//
//// ���������� ��������� ����� ��� ����� ������
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