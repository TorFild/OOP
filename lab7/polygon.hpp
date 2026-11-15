template <class	T>
class Polygon {
private:
	int vertexCount;
	T* x;
	T* y;
	void Allocate(int count);
	void Free();
public:
	Polygon();
	Polygon(int count);
	Polygon(int count, const T* coords);
	Polygon(int count, double radius);
	Polygon(const Polygon&other);
	~Polygon();
	int GetVertexCount() const { return vertexCount; }


	bool SetVertex(int index, T x_val, T y_val);
	T GetVertexX(int index) const;
	T GetVertexY(int index) const;
	double GetArea() const;

	void Print() const;

};
