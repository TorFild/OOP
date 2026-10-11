#include <iostream>
#include <windows.h>
#include "lift.hpp"

using namespace std;

int main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	Lift Mylift;
	Mylift.Reset();


	int choice;
	do {
		system("cls");
		Mylift.PrintState();

		cout << "\n--- МЕНЮ КЕРУВАННЯ ---" << endl;
		cout << "1 - Викликати ліфт на поверх (Start)" << endl;
		cout << "2 - Ліфт прибув на виклик (End)" << endl;
		cout << "3 - Завантажити кабіну (LoadCabin)" << endl;
		cout << "4 - Запустити ліфт з пасажирами (Launch)" << endl;
		cout << "5 - Зупинити ліфт (Stop)" << endl;
		cout << "0 - Вихід" << endl;
		cout << "Оберіть дію: ";
		cin >> choice;


		switch (choice) {
		case 1: {
			int target;
			cout << "Введіть номер поверху для виклику: ";
			cin >> target;
			Mylift.Start(target);
			break;
		}

		case 2: {
			int reached;
			cout << "Введіть номер кінцевого поверху: ";
			cin >> reached;
			Mylift.End(reached);
			break;
		}

		case 3: {
			int weight;
			cout << "Введіть вагуу кг для завантаження в ліфт: ";
			cin >> weight;
			Mylift.LoadCabin(weight);
			break;
		}

		case 4: {
			int target;
			cout << "Введіть номер поверху, на який їдуть пасажири: ";
			cin >> target;
			Mylift.Launch(target);
			break;
		}

		case 5: {
			int reached;
			cout << "Введіть номер поверху, на якому зупинився ліфт: ";
			cin >> reached;
			Mylift.Stop(reached);
			break;
		}

		case 0: {
			break;
		default:
			cout << "Невірний вибір!" << endl;
		}
		} 


	} while (choice != 0);
	


	return 0;
}
