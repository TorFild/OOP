#pragma once
#include <string>

using namespace std;

template <typename T>
class operation {
protected:
    T** matrix;
    int n;
    T resValue;
    int resRow;
    int resCol;

public:
    operation(T** mat, int size);
    virtual ~operation();

    virtual void execute() = 0;

    T getResValue() const;
    int getResRow() const;
    int getResCol() const;
};

template <typename T>
class MinAboveMain : public operation<T> {
public:
    MinAboveMain(T** mat, int size);
    void execute() override;
};

template <typename T>
class MaxAboveMain : public operation<T> {
public:
    MaxAboveMain(T** mat, int size);
    void execute() override;
};

template <typename T>
class MinBelowMain : public operation<T> {
public:
    MinBelowMain(T** mat, int size);
    void execute() override;
};

template <typename T>
class MaxBelowMain : public operation<T> {
public:
    MaxBelowMain(T** mat, int size);
    void execute() override;
};

template <typename T>
class MinAboveSec : public operation<T> {
public:
    MinAboveSec(T** mat, int size);
    void execute() override;
};

template <typename T>
class MaxAboveSec : public operation<T> {
public:
    MaxAboveSec(T** mat, int size);
    void execute() override;
};

template <typename T>
class MinBelowSec : public operation<T> {
public:
    MinBelowSec(T** mat, int size);
    void execute() override;
};

template <typename T>
class MaxBelowSec : public operation<T> {
public:
    MaxBelowSec(T** mat, int size);
    void execute() override;
};

template <typename T>
operation<T>* createOperation(const string& cmd, T** mat, int n);
