#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "operation.hpp"

using namespace std;

string cleanToken(const string& s) {
    string res;
    for (char c : s) {
        if (c != '<' && c != '>' && c != '[' && c != ']') {
            res += c;
        }
    }
    return res;
}

string getCommandDescription(const string& cmd) {
    if (cmd == "MinAboveMain") return "Пошук min елемента над головною діагоналлю";
    if (cmd == "MaxAboveMain") return "Пошук max елемента над головною діагоналлю";
    if (cmd == "MinBelowMain") return "Пошук min елемента під головною діагоналлю";
    if (cmd == "MaxBelowMain") return "Пошук max елемента під головною діагоналлю";
    if (cmd == "MinAboveSec")  return "Пошук min елемента над побічною діагоналлю";
    if (cmd == "MaxAboveSec")  return "Пошук max елемента над побічною діагоналлю";
    if (cmd == "MinBelowSec")  return "Пошук min елемента під побічною діагоналлю";
    if (cmd == "MaxBelowSec")  return "Пошук max елемента під побічною діагоналлю";
    return "Невідома операція";
}

template <typename T>
void writeResult(ofstream& fout, int k, const string& cmd, T** mat, int n, const operation<T>* ptr) {
    fout << "Матриця " << k << " (розмірність: " << n << "x" << n << ")\n";
    fout << "Команда: " << cmd << " (" << getCommandDescription(cmd) << ")\n";
    fout << "Початкова матриця:\n";
    for (int i = 0; i < n; ++i) {
        fout << "[";
        for (int j = 0; j < n; ++j) {
            fout << setw(6) << fixed << setprecision(1) << mat[i][j];
            if (j < n - 1) fout << ",";
        }
        fout << " ]\n";
    }
    fout << "Результат: знайдено елемент " << fixed << setprecision(1) << ptr->getResValue()
        << " (рядок: " << ptr->getResRow() << ", стовпець: " << ptr->getResCol() << ")\n";
    fout << "----------------------------------------------------------------------\n";
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string filename;
    cout << "====================================================\n";
    cout << "       ПРОГРАМА ОБРОБКИ КВАДРАТНИХ МАТРИЦЬ\n";
    cout << "====================================================\n";
    cout << "Введіть назву вхідного файлу (наприклад, input.txt): ";
    cin >> filename;

    ifstream fin(filename);
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "\n[!] Error: файл не знайдено (" << filename << ").\n";
        return 1;
    }

    cout << "\n[+] Файли успішно відкрито. Розпочато пакетну обробку...\n\n";

    fout << "======================================================================\n";
    fout << "                    ЗВІТ ПРО ОПРАЦЮВАННЯ МАТРИЦЬ\n";
    fout << "======================================================================\n";

    int k = 1;
    string rawCmd;

    while (fin >> rawCmd) {
        string cmd = cleanToken(rawCmd);

        string nextTok;
        if (!(fin >> nextTok)) break;
        nextTok = cleanToken(nextTok);

        if (!isdigit(nextTok[0]) && nextTok[0] != '-') {
            if (!(fin >> nextTok)) break;
            nextTok = cleanToken(nextTok);
        }
        int n = stoi(nextTok);

        if (n < 2) {
            string dummy;
            for (int i = 0; i < n * n; ++i) fin >> dummy;

            fout << "Матриця " << k << " (розмірність: " << n << "x" << n << ")\n";
            fout << "Помилка: некоректна розмірність матриці (n = " << n << ") для пошуку поза діагоналлю.\n";
            fout << "----------------------------------------------------------------------\n";
            cout << "Матриця №" << k << " (" << cmd << "): Помилка розмірності (n = " << n << ")\n";
            k++;
            continue;
        }

        double** tempMat = new double* [n];
        for (int i = 0; i < n; ++i) {
            tempMat[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                string valStr;
                fin >> valStr;
                tempMat[i][j] = stod(cleanToken(valStr));
            }
        }

        operation<double>* ptr = createOperation<double>(cmd, tempMat, n);

        if (ptr != nullptr) {
            ptr->execute();
            writeResult(fout, k, cmd, tempMat, n, ptr);
            cout << "Матриця №" << k << " (" << cmd << ", " << n << "x" << n << "): Успішно! Екстремум = "
                << fixed << setprecision(1) << ptr->getResValue()
                << " [" << ptr->getResRow() << "][" << ptr->getResCol() << "]\n";
            delete ptr;
        }
        else {
            fout << "Матриця " << k << " (розмірність: " << n << "x" << n << ")\n";
            fout << "Помилка: невідома команда операції (" << cmd << ").\n";
            fout << "----------------------------------------------------------------------\n";
            cout << "Матриця №" << k << " (" << cmd << "): Помилка! Невідома команда.\n";
        }

        for (int i = 0; i < n; ++i) delete[] tempMat[i];
        delete[] tempMat;

        k++;
    }

    fout << "======================================================================\n";

    fin.close();
    fout.close();

    cout << "\n====================================================\n";
    cout << "[+] Обробку завершено! Всі звіти збережено у файл output.txt\n";
    return 0;
}
