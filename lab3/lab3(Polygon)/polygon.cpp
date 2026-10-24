#include "polygon.hpp"
#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>


void Polygon::Allocate(int count) {
	vertexCount = count;
	x = new double[count];
	y = new double[count];
}

void Polygon::Free() {

	delete[] x;
	delete[] y;
	vertexCount = 0;

	x = nullptr;
	y = nullptr;

}


Polygon::Polygon() {
	vertexCount = 0;
	x = nullptr;
	y = nullptr;
}

Polygon::~Polygon() {
	Free();
}

Polygon::Polygon(int count) {
	Allocate(count);
	for (int i = 0; i < count; i++) {
		x[i] = 0;
		y[i] = 0;
	}
}

Polygon::Polygon(const Polygon& other) {
	Allocate(other.vertexCount);
	for (int i = 0; i < other.vertexCount; i++) {
		x[i] = other.x[i];
		y[i] = other.y[i];
	}
}

Polygon::Polygon(int count, const double* coords) {
	Allocate(count);
	for (int i = 0; i < count; i++)
	{
		x[i] = coords[i*2];
		y[i] = coords[i * 2 + 1];
	}
}

Polygon::Polygon(int count, double radius) {
	Allocate(count);
	double angleStep = 2 * M_PI / count;
	for (int i = 0; i < count; i++)
	{
		double currentAngle = i * angleStep;
		x[i] = radius * cos(currentAngle);
		y[i] = radius * sin(currentAngle);

	}
}

bool Polygon::SetVertex(int index, double x_val, double  y_val) {
	if(index >= 0 && index < vertexCount){
		x[index] = x_val;
		y[index] = y_val;
		return true;
	}
	else {
		return false;
	}
}

double Polygon::GetVertexX(int index) const {
	if (index >= 0 && index < vertexCount) {
		return x[index];
	}
	else {
		return 0.0;
	}
}

double Polygon::GetVertexY(int index) const {
	if (index >= 0 && index < vertexCount) {
		return y[index];
	}
	else {
		return 0.0;
	}
}

double Polygon::GetArea() const {
	double area = 0;
	for (int i = 0; i < vertexCount; i++)
	{
		int j = (i + 1) % vertexCount;
		area += (x[i] * y[j]) - (x[j] * y[i]);
	}
	return std::abs(area) / 2.0;
}

void Polygon::Print() const {
	std::cout << "Багатокутник (" << vertexCount << " вершин):" << std::endl;
	for (int i = 0; i < vertexCount; i++) {
		std::cout << "  Вершина " << i << ": (" << x[i] << ", " << y[i] << ")" << std::endl;
	}
}



