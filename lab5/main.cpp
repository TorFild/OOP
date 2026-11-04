#include <iostream>
#include <windows.h>
#include "space_objects.hpp"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);

    cout << "--- Перевірка Паралелепіпеда ---" << endl;
    Parallelepiped p1(0, 0, 0, 2, 3, 4);
    cout << "Початковий об'єм паралелепіпеда: " << p1.GetVolume() << endl;

    p1.Move(5, 5, -2);

    p1.ScaleVolume(192);
    cout << "Об'єм після пропорційної зміни: " << p1.GetVolume() << endl;

    cout << "\n--- Перевірка Сфери ---" << endl;
    Sphere s1(1, 1, 1, 3);
    cout << "Початковий об'єм сфери: " << s1.GetVolume() << endl;

    Sphere s2(s1);

    s2.ScaleToVolume(500);
    cout << "Об'єм сфери-копії після масштабування: " << s2.GetVolume() << endl;

    return 0;
}
