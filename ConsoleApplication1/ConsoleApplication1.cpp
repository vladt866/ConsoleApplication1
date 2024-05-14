#include <iostream>  //6.1 
#include <string>

using namespace std;

class Entity {
protected:
    int Xmin, Ymin, Xmax, Ymax;

public:
    Entity(int x1, int y1, int x2, int y2) : Xmin(x1), Ymin(y1), Xmax(x2), Ymax(y2) {}

    virtual void printInfo() = 0;
};

class Pedestrian : public Entity {
private:
    string gender;
    string beard;

public:
    Pedestrian(int x1, int y1, int x2, int y2, string gen, string beardStatus);

    void printInfo() override;
};

class Cyclist : public Entity {
private:
    bool isChild;
    string glasses;
    string bikeColor;

public:
    Cyclist(int x1, int y1, int x2, int y2, bool child, string glass, string color);

    void printInfo() override;
};

class Car : public Entity {
private:
    string color;
    string number;
    bool isTaxi;

public:
    Car(int x1, int y1, int x2, int y2, std::string c, std::string num, bool taxi);

    void printInfo() override;
};

class UnattendedBag : public Entity {
private:
    int timeFirstSeen;

public:
    UnattendedBag(int x1, int y1, int x2, int y2, int time);

    void printInfo() override;
};

Pedestrian::Pedestrian(int x1, int y1, int x2, int y2, std::string gen, std::string beardStatus) : Entity(x1, y1, x2, y2), gender(gen), beard(beardStatus) {}

void Pedestrian::printInfo() {
    cout << "Пешеход на позиции (" << Xmin << ", " << Ymin << ") - (" << Xmax << ", " << Ymax << "), Пол: " << gender << ", Борода: " << beard << endl;
}

Cyclist::Cyclist(int x1, int y1, int x2, int y2, bool child, std::string glass, std::string color) : Entity(x1, y1, x2, y2), isChild(child), glasses(glass), bikeColor(color) {}

void Cyclist::printInfo() {
    cout << "Велосипедист на позиции (" << Xmin << ", " << Ymin << ") - (" << Xmax << ", " << Ymax << "), Ребенок: " << (isChild ? "Да" : "Нет") << ", Очки: " << glasses << ", Цвет велосипеда: " << bikeColor << endl;
}

Car::Car(int x1, int y1, int x2, int y2, std::string c, std::string num, bool taxi) : Entity(x1, y1, x2, y2), color(c), number(num), isTaxi(taxi) {}

void Car::printInfo() {
    cout << "Машина на позиции (" << Xmin << ", " << Ymin << ") - (" << Xmax << ", " << Ymax << "), Цвет: " << color << ", Номер: " << number << ", Такси: " << (isTaxi ? "Да" : "Нет") << endl;
}

UnattendedBag::UnattendedBag(int x1, int y1, int x2, int y2, int time) : Entity(x1, y1, x2, y2), timeFirstSeen(time) {}

void UnattendedBag::printInfo() {
    cout << "Брошенная сумка на позиции (" << Xmin << ", " << Ymin << ") - (" << Xmax << ", " << Ymax << "), Время первого обнаружения: " << timeFirstSeen << " секунд после полуночи" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    // Ввод данных о пешеходе
    int px1, py1, px2, py2;
    string pgender, pbeard;

    cout << "Введите координаты пешехода (x1 y1 x2 y2): ";
    cin >> px1 >> py1 >> px2 >> py2;

    cout << "Введите пол пешехода и статус бороды: ";
    cin >> pgender >> pbeard;

    Pedestrian person(px1, py1, px2, py2, pgender, pbeard);

    // Ввод данных о велосипедисте
    int cx1, cy1, cx2, cy2;
    bool cchild;
    string cglasses, cbikeColor;

    cout << "Введите координаты велосипедиста (x1 y1 x2 y2): ";
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    cout << "Является ли велосипедист ребенком? (0 - Нет / 1 - Да): ";
    cin >> cchild;

    cout << "Введите информацию об очках и цвете велосипеда: ";
    cin >> cglasses >> cbikeColor;

    Cyclist cyclist(cx1, cy1, cx2, cy2, cchild, cglasses, cbikeColor);

    // Ввод данных о машине
    int carx1, cary1, carx2, cary2;
    string carColor, carNumber;
    bool carIsTaxi;

    cout << "Введите координаты машины (x1 y1 x2 y2): ";
    cin >> carx1 >> cary1 >> carx2 >> cary2;

    cout << "Введите цвет машины и номерной знак: ";
    cin >> carColor >> carNumber;

    cout << "Это такси? (0 - Нет / 1 - Да): ";
    cin >> carIsTaxi;

    Car car(carx1, cary1, carx2, cary2, carColor, carNumber, carIsTaxi);

    // Ввод данных о брошенной сумке
    int bagx1, bagy1, bagx2, bagy2;
    int timeFirstSeen;

    cout << "Введите координаты брошенной сумки (x1 y1 x2 y2): ";
    cin >> bagx1 >> bagy1 >> bagx2 >> bagy2;

    cout << "Введите время первого обнаружения (в секундах после полуночи): ";
    cin >> timeFirstSeen;

    UnattendedBag bag(bagx1, bagy1, bagx2, bagy2, timeFirstSeen);

    // Вывод информации
    person.printInfo();
    cyclist.printInfo();
    car.printInfo();
    bag.printInfo();

    return 0;
}


