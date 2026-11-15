#include <iostream>
#define NOGDI
#include <windows.h>
#include "polygon.hpp"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "=== 1. Тестування Polygon<int> (цілочисельні координати) ===" << endl;
    int intCoords[] = { 0, 0, 4, 0, 4, 3, 0, 3 };
    Polygon<int> rectInt(4, intCoords);

    rectInt.Print();
    cout << "Площа прямокутника (int): " << rectInt.GetArea() << endl;

    rectInt.SetVertex(2, 6, 3);
    cout << "Координата X вершини 2 після зміни: " << rectInt.GetVertexX(2) << endl;
    cout << "Нова площа після зміни вершини: " << rectInt.GetArea() << "\n\n";


    cout << "=== 2. Тестування Polygon<double> (дійсні координати) ===" << endl;
    Polygon<double> hexDouble(6, 5.5);

    hexDouble.Print();
    cout << "Площа правильного шестикутника (double): " << hexDouble.GetArea() << "\n\n";


    cout << "=== 3. Тестування Polygon<float> та конструктора копіювання ===" << endl;
    Polygon<float> triFloat(3);
    triFloat.SetVertex(0, 0.0f, 0.0f);
    triFloat.SetVertex(1, 3.5f, 0.0f);
    triFloat.SetVertex(2, 0.0f, 2.0f);

    Polygon<float> triCopy(triFloat);
    triCopy.Print();
    cout << "Площа скопійованого трикутника (float): " << triCopy.GetArea() << endl;

    return 0;
}
