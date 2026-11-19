#include "operation.hpp"


template <typename T>
operation<T>::operation(T** mat, int size) : n(size), resValue(T()), resRow(-1), resCol(-1) {
    matrix = new T * [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new T[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = mat[i][j];
        }
    }
}

template <typename T>
operation<T>::~operation() {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
T operation<T>::getResValue() const { return resValue; }

template <typename T>
int operation<T>::getResRow() const { return resRow; }

template <typename T>
int operation<T>::getResCol() const { return resCol; }


template <typename T>
MinAboveMain<T>::MinAboveMain(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MinAboveMain<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i < j) {
                if (first || this->matrix[i][j] < this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MaxAboveMain<T>::MaxAboveMain(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MaxAboveMain<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i < j) {
                if (first || this->matrix[i][j] > this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MinBelowMain<T>::MinBelowMain(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MinBelowMain<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i > j) {
                if (first || this->matrix[i][j] < this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MaxBelowMain<T>::MaxBelowMain(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MaxBelowMain<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i > j) {
                if (first || this->matrix[i][j] > this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MinAboveSec<T>::MinAboveSec(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MinAboveSec<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i + j < this->n - 1) {
                if (first || this->matrix[i][j] < this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MaxAboveSec<T>::MaxAboveSec(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MaxAboveSec<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i + j < this->n - 1) {
                if (first || this->matrix[i][j] > this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MinBelowSec<T>::MinBelowSec(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MinBelowSec<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i + j > this->n - 1) {
                if (first || this->matrix[i][j] < this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
MaxBelowSec<T>::MaxBelowSec(T** mat, int size) : operation<T>(mat, size) {}

template <typename T>
void MaxBelowSec<T>::execute() {
    bool first = true;
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->n; ++j) {
            if (i + j > this->n - 1) {
                if (first || this->matrix[i][j] > this->resValue) {
                    this->resValue = this->matrix[i][j];
                    this->resRow = i;
                    this->resCol = j;
                    first = false;
                }
            }
        }
    }
}


template <typename T>
operation<T>* createOperation(const string& cmd, T** mat, int n) {
    if (cmd == "MinAboveMain") return new MinAboveMain<T>(mat, n);
    if (cmd == "MaxAboveMain") return new MaxAboveMain<T>(mat, n);
    if (cmd == "MinBelowMain") return new MinBelowMain<T>(mat, n);
    if (cmd == "MaxBelowMain") return new MaxBelowMain<T>(mat, n);
    if (cmd == "MinAboveSec")  return new MinAboveSec<T>(mat, n);
    if (cmd == "MaxAboveSec")  return new MaxAboveSec<T>(mat, n);
    if (cmd == "MinBelowSec")  return new MinBelowSec<T>(mat, n);
    if (cmd == "MaxBelowSec")  return new MaxBelowSec<T>(mat, n);
    return nullptr;
}


template class operation<double>;
template class MinAboveMain<double>;
template class MaxAboveMain<double>;
template class MinBelowMain<double>;
template class MaxBelowMain<double>;
template class MinAboveSec<double>;
template class MaxAboveSec<double>;
template class MinBelowSec<double>;
template class MaxBelowSec<double>;
template operation<double>* createOperation<double>(const string&, double**, int);

template class operation<int>;
template class MinAboveMain<int>;
template class MaxAboveMain<int>;
template class MinBelowMain<int>;
template class MaxBelowMain<int>;
template class MinAboveSec<int>;
template class MaxAboveSec<int>;
template class MinBelowSec<int>;
template class MaxBelowSec<int>;
template operation<int>* createOperation<int>(const string&, int**, int);

template class operation<float>;
template class MinAboveMain<float>;
template class MaxAboveMain<float>;
template class MinBelowMain<float>;
template class MaxBelowMain<float>;
template class MinAboveSec<float>;
template class MaxAboveSec<float>;
template class MinBelowSec<float>;
template class MaxBelowSec<float>;
template operation<float>* createOperation<float>(const string&, float**, int);
