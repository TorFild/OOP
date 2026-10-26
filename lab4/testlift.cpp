#include <iostream>
#include <windows.h>
#include "lift.hpp"

using namespace std;

int main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "--- Ліфт 1 (За замовчуванням) ---" << endl;
	Lift lift1;
	lift1.PrintState();

	cout << "\n--- Ліфт 2 (Ініціалізація: 5 поверх, 100 кг) ---" << endl;
	Lift lift2(5, 100);
	lift2.PrintState();

	cout << "\n--- Ліфт 3 (Копія Ліфта 2) ---" << endl;
	Lift lift3(lift2);
	lift3.PrintState();

	cout << endl;


	system("pause");
	int choice;
	do {
		system("cls");
		lift1.PrintState();

		cout << "\n--- МЕНЮ КЕРУВАННЯ ---" << endl;
		cout << "1 - Викликати ліфт на поверх (Старт виклику '++')" << endl;
		cout << "2 - Ліфт прибув на виклик (Кінець виклику '--')" << endl;
		cout << "3 - Завантажити кабіну (Оператор '+=')" << endl;
		cout << "0 - Вихід" << endl;
		cout << "Оберіть дію: ";
		cin >> choice;


		switch (choice) {
		case 1: {
			int target;
			cout << "Введіть номер поверху для виклику: ";
			cin >> target;
			lift1.SetFloor(target);
			++lift1;
			break;
		}

		case 2: {
			int reached;
			cout << "Введіть номер кінцевого поверху: ";
			cin >> reached;
			lift1.SetFloor(reached);
			--lift1;
			break;
		}

		case 3: {
			int weight;
			cout << "Введіть вагуу кг для завантаження в ліфт: ";
			cin >> weight;
			lift1 += weight;
			break;
		}

		case 4: {
			int target;
			cout << "Введіть номер поверху, на який їдуть пасажири: ";
			cin >> target;
			lift1.Launch(target);
			break;
		}

		case 5: {
			int reached;
			cout << "Введіть номер поверху, на якому зупинився ліфт: ";
			cin >> reached;
			lift1.Stop(reached);
			break;
		}

		case 0: {
			break;
		}
		default:
			cout << "Невірний вибір!" << endl;
		}

		if (choice != 0) {
			cout << endl;
			system("pause");
		}


	} while (choice != 0);



	return 0;
}
