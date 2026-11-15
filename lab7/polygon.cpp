#include "polygon.hpp"
#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>


template <class T>
void Polygon<T>::Allocate(int count) {
	vertexCount = count;
	x = new T[count];
	y = new T[count];
}

template <class T>
void Polygon<T>::Free() {

	delete[] x;
	delete[] y;
	vertexCount = 0;

	x = nullptr;
	y = nullptr;

}

template <class T>
Polygon<T>::Polygon() {
	vertexCount = 0;
	x = nullptr;
	y = nullptr;
}

template <class T>
Polygon<T>::~Polygon() {
	Free();
}

template <class T>
Polygon<T>::Polygon(int count) {
	Allocate(count);
	for (int i = 0; i < count; i++) {
		x[i] = 0;
		y[i] = 0;
	}
}

template <class T>
Polygon<T>::Polygon(const Polygon& other) {
	Allocate(other.vertexCount);
	for (int i = 0; i < other.vertexCount; i++) {
		x[i] = other.x[i];
		y[i] = other.y[i];
	}
}
template <class T>
Polygon<T>::Polygon(int count, const T* coords) {
	Allocate(count);
	for (int i = 0; i < count; i++)
	{
		x[i] = coords[i*2];
		y[i] = coords[i * 2 + 1];
	}
}

template <class T>
Polygon<T>::Polygon(int count, double radius) {
	Allocate(count);
	double angleStep = 2 * M_PI / count;
	for (int i = 0; i < count; i++)
	{
		double currentAngle = i * angleStep;
		x[i] = static_cast<T>(radius * cos(currentAngle));
		y[i] = static_cast<T>(radius * sin(currentAngle));

	}
}

template <class T>
bool Polygon<T>::SetVertex(int index, T x_val, T  y_val) {
	if(index >= 0 && index < vertexCount){
		x[index] = x_val;
		y[index] = y_val;
		return true;
	}
	else {
		return false;
	}
}
template <class T>
T Polygon<T>::GetVertexX(int index) const {
	if (index >= 0 && index < vertexCount) {
		return x[index];
	}
	else {
		return 0;
	}
}

template <class T>
T Polygon<T>::GetVertexY(int index) const {
	if (index >= 0 && index < vertexCount) {
		return y[index];
	}
	else {
		return 0;
	}
}
template <class T>
double Polygon<T>::GetArea() const {
	double area = 0;
	for (int i = 0; i < vertexCount; i++)
	{
		int j = (i + 1) % vertexCount;
		area += (x[i] * y[j]) - (x[j] * y[i]);
	}
	return std::abs(area) / 2.0;
}
template <class T>
void Polygon<T>::Print() const {
	std::cout << "Багатокутник (" << vertexCount << " вершин):" << std::endl;
	for (int i = 0; i < vertexCount; i++) {
		std::cout << "  Вершина " << i << ": (" << x[i] << ", " << y[i] << ")" << std::endl;
	}
}


template class Polygon<int>;
template class Polygon<double>;
template class Polygon<float>;


