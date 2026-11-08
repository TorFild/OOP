#include <iostream>
#include <windows.h>
#include "space_objects.hpp"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);

   

    SpaceObject* objPtr;

    cout << "--- Демонстрація поліморфізму: Паралелепіпед ---" << endl;

    Parallelepiped* p = new Parallelepiped(0, 0, 0, 2, 3, 4);
    cout << "Початковий об'єм: " << p->GetVolume() << endl;

    objPtr = p;

    objPtr->ScaleToVolume(192);
    cout << "Об'єм після поліморфного масштабування: " << p->GetVolume() << endl;

    cout << "\n--- Демонстрація поліморфізму: Сфера ---" << endl;
    Sphere* s = new Sphere(1, 1, 1, 3);
    cout << "Початковий об'єм: " << s->GetVolume() << endl;

    objPtr = s;

    objPtr->ScaleToVolume(500);

    cout << "Об'єм після поліморфного масштабування: " << s->GetVolume() << endl;

    delete p;
    delete s;



    return 0;
}
