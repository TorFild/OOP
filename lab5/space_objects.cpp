#define _USE_MATH_DEFINES
#include "space_objects.hpp"
#include <iostream>
#include <cmath>
using namespace std;

SpaceObject::SpaceObject() {
	x = y = z = 0;
}

SpaceObject::SpaceObject(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

SpaceObject::SpaceObject(const SpaceObject& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

void SpaceObject::Move(double dx, double dy, double dz){
	x += dx;
	y += dy;
	z += dz;
}


Parallelepiped::Parallelepiped() :SpaceObject() {
	height = width = length = 0;
}

Parallelepiped::Parallelepiped(double x, double y, double z, double height, double width, double length) :SpaceObject(x, y, z) {
	this->height = height;
	this->length = length;
	this->width = width;
}

Parallelepiped::Parallelepiped(const Parallelepiped& other) : SpaceObject(other) {
	this->height = other.height;
	this->length = other.length;
	this->width = other.width;
}


void Parallelepiped::ChangeSize(double newH, double newW, double newL) {
	height = newH;
	width = newW;
	length = newL;
}

double Parallelepiped::GetVolume() {
	return height * width * length;
}

void Parallelepiped::ScaleVolume(double targetVolume) {
	double currentVolume = GetVolume();

	if (currentVolume > 0) {
		double k = cbrt(targetVolume / currentVolume);
		height *= k;
		width *= k;
		length *= k;
	}
	else
	{
		cout << "Помилка. Об'єм менше нуля ! " << endl;
	}

}


Sphere::Sphere() :SpaceObject(){
	radius = 0;
}

Sphere::Sphere(double x, double y, double z, double radius) :SpaceObject(x, y, z) {
	this->radius = radius;
}

Sphere::Sphere(const Sphere& other) :SpaceObject(other) {
	this->radius = other.radius;
}

void Sphere::ChangeRadius(double newRadius) {
	radius = newRadius;
}

double Sphere::GetVolume() {
	return 4.0/3.0 * M_PI * pow(radius, 3);
}

void Sphere::ScaleToVolume(double targetVolume) {
	if (targetVolume > 0) {
		radius = cbrt((3.0 * targetVolume) / (4.0 * M_PI));
	}
	else {
		cout << "Помилка. Об'єм має бути більшим за нуль!" << endl;
	}
}


