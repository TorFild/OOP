#include <iostream>
#define NOGDI
#include <windows.h>
#include "polygon.hpp"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "--- ТЕСТУВАННЯ КЛАСУ ДИНАМІЧНИЙ БАГАТОКУТНИК ---" << endl;

    cout << "1. Конструктор за замовчуванням (порожній):" << endl;
    Polygon p1;
    p1.Print();

    cout << "\n2. Конструктор ініціалізації (3 вершини, заповнені нулями):" << endl;
    Polygon p2(3);
    p2.Print();

    cout << "\n3. Конструктор ініціалізації з масиву (прямокутник 4x3):" << endl;
    double coords[] = { 0, 0, 4, 0, 4, 3, 0, 3 };
    Polygon p3(4, coords);
    p3.Print();
    cout << "Площа p3: " << p3.GetArea() << endl;

    cout << "\n4. Конструктор математичний (правильний шестикутник, радіус 5):" << endl;
    Polygon p4(6, 5.0);
    p4.Print();
    cout << "Площа p4: " << p4.GetArea() << endl;

    cout << "\n5. Конструктор копіювання (копія прямокутника p3):" << endl;
    Polygon p5(p3);
    p5.Print();
    cout << "Площа p5: " << p5.GetArea() << endl;
    cout << endl;

    cout << "\n6. Тестування методів доступу (зміна координат):" << endl;
    p2.SetVertex(0, 10.5, 20.5);
    cout << "Встановлено нові координати для вершини 0 об'єкта p2." << endl;

    cout << "Прочитана координата X: " << p2.GetVertexX(0) << endl;
    cout << "Прочитана координата Y: " << p2.GetVertexY(0) << endl;

    cout << "Оновлений вигляд p2:" << endl;
    p2.Print();


    system("pause");
    return 0;
}
