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
	Lift();
	Lift(int FloorNum, int FloorWeight);
	Lift(const Lift& other);

	void Start(int targetFloor);
	void End(int reachedFloor);
	void LoadCabin(int FloorWeight);
	void Launch(int targetFloor);
	void Stop(int reachedFloor);

	Lift& operator+=(int extraWeight);
	Lift& operator++();
	Lift& operator--();



	void PrintState();
	void SetFloor(int floor) {
		FloorNum = floor; 
	}

	int GetFloorNum() { return FloorNum; }
	bool GetDoorsState() { return DoorsState; }
	EngineState GetEngineCon() { return EngineCon; }
	GeneralState GetGeneralCon() { return GeneralCon; }
	int GetFloorWeight() { return FloorWeight; }

};
