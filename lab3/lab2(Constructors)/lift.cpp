#include <iostream>
#include "lift.hpp"

using namespace std;

  Lift::Lift() {
	FloorNum = 1;
	DoorsState = false;
	EngineCon = STOPPED;
	FloorWeight = 0;
	GeneralCon = IDLE;
}

  Lift::Lift(int FloorNum, int FloorWeight) {
	  this->FloorNum = FloorNum;
	  this->FloorWeight = FloorWeight;
	  DoorsState = false;
	  EngineCon = STOPPED;
	  GeneralCon = IDLE;
  }

  Lift::Lift(const Lift& other) {
	  FloorNum = other.FloorNum;
	  DoorsState = other.DoorsState;
	  EngineCon = other.EngineCon;
	  FloorWeight = other.FloorWeight;
	  GeneralCon = other.GeneralCon;
  }

void Lift::Start(int targetFloor) {
	DoorsState = false;

	if(targetFloor > FloorNum)  {
		EngineCon = UP;
	}
	else if(targetFloor < FloorNum) {
		EngineCon = DOWN;
	}
	else {
		DoorsState = true;
	}
	GeneralCon = CALL;
}

void Lift::End(int reachedFloor) {
	EngineCon = STOPPED;
	FloorNum = reachedFloor;
	DoorsState = true;
	GeneralCon = IDLE;
}

void Lift::LoadCabin(int weight) {
	FloorWeight = weight;
}

void Lift::Launch(int targetFloor) {
	if (FloorWeight > 0 && FloorWeight <= 250) {
		DoorsState = false;
		if (targetFloor > FloorNum) {
			EngineCon = UP;
		}
		else if (targetFloor < FloorNum) {
			EngineCon = DOWN;
		}
		else {
			DoorsState = true;
		}
		GeneralCon = TRANSPORT;
	}
}

void Lift::Stop(int reachedFloor) {
	EngineCon = STOPPED;
	FloorNum = reachedFloor;
	DoorsState = true;
	GeneralCon = IDLE;
}


void Lift::PrintState() {
	cout << "\n------------СТАН ЛІФТА------------" << endl;
	cout << "Поточний номер поверху: " << FloorNum << endl;
	cout << "Стан дверцят - " << (DoorsState ? "Відчинені" : "Зачинені") << endl;
	cout << "Поточна вага ліфта: " << FloorWeight << endl;
	
	cout << "Загальний стан ліфта - ";
	if (GeneralCon == IDLE) cout << "Простій" << endl;
	else if (GeneralCon == CALL) cout << "Виклик" << endl;
	else cout << "Перевезення" << endl;


	cout << "Стан двигуна - ";
	if (EngineCon == STOPPED) cout << "Вимкнений" << endl;
	else if (EngineCon == UP) cout << "Підйом" << endl;
	else cout << "Спуск" << endl;
}

