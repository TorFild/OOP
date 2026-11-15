#pragma once
#include <iostream>
#include <exception>

using namespace std;

class OverloadException : public exception {
public:
	OverloadException() : exception("Помилка : Перевантаження ліфта!Вага перевищує 250 кг.") {}
};



enum GeneralState { IDLE, CALL, TRANSPORT };
enum EngineState { STOPPED, UP, DOWN };

class Lift {
private:
	GeneralState GeneralCon;
	EngineState EngineCon;
	bool DoorsState;
	int FloorNum;
	int FloorWeight;

public:
	void Start(int targetFloor);
	void End(int reachedFloor);
	void LoadCabin(int FloorWeight);
	void Launch(int targetFloor);
	void Stop(int reachedFloor);
	void Reset();

	void PrintState();


	int GetFloorNum() { return FloorNum; }
	bool GetDoorsState() { return DoorsState; }
	EngineState GetEngineCon() { return EngineCon; }
	GeneralState GetGeneralCon() { return GeneralCon; }
	int GetFloorWeight() { return FloorWeight; }

};



