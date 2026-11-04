
class SpaceObject {
protected:
	double x, y, z;
public:
	SpaceObject();
	SpaceObject(double x, double y, double z);
	SpaceObject(const SpaceObject& other);

	void Move(double dx, double dy, double dz);
	double GetX() { return x; }
	double GetY() { return y; }
	double GetZ() { return z; }

};


class Parallelepiped:public SpaceObject {
private:
	double height;
	double width;
	double length;
public:
	Parallelepiped();
	Parallelepiped(double x, double y, double z, double height, double width, double length);
	Parallelepiped(const Parallelepiped& other);

	void ScaleVolume(double targetVolume);
	void ChangeSize(double newH, double newW, double newL);
	double GetVolume();
};



class Sphere :public SpaceObject {
private:
	double radius;
public:
	Sphere();
	Sphere(double x, double y, double z, double radius);
	Sphere(const Sphere& other);

	void ScaleToVolume(double targetVolume);
	void ChangeRadius(double newRadius);
	double GetVolume();
};


