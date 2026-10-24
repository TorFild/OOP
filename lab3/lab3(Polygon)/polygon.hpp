class Polygon {
private:
	int vertexCount;
	double* x;
	double* y;
	void Allocate(int count);
	void Free();
public:
	Polygon();
	Polygon(int count);
	Polygon(int count, const double* coords);
	Polygon(int count, double radius);
	Polygon(const Polygon&other);
	~Polygon();
	int GetVertexCount() const { return vertexCount; }


	bool SetVertex(int index, double x_val, double y_val);
	double GetVertexX(int index) const;
	double GetVertexY(int index) const;
	double GetArea() const;

	void Print() const;

};
