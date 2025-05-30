#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

void InputMatrix(vector<vector<bool>>& matr) {
    cout << "Введите матрицу (0/1): " << endl;
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr.size(); j++) {
            int elem;
            cin >> elem;
            if (elem == 1) {
                matr[i][j] = true;
            }
            else {
                matr[i][j] = false;
            }
        }
    }
}

void OutputMatrix(const vector<vector<bool>>& matr, const string& title) {
    cout << title << endl;
    for (const auto& row : matr) {
        for (bool val : row) {
            if (val) {
                cout << '1';
            }
            else {
                cout << '0';
            }
            cout << " ";
        }
        cout << endl;
    }
}

bool IsReflexive(const vector<vector<bool>>& matr) {
    for (int i = 0; i < matr.size(); i++) {
        if (!matr[i][i]) return false;
    }
    return true;
}

bool IsSymmetric(const vector<vector<bool>>& matr) {
    for (int i = 0; i < matr.size(); i++) {
        for (int j = i + 1; j < matr.size(); j++) {
            if (matr[i][j] != matr[j][i]) return false;
        }
    }
    return true;
}

bool IsAntisymmetric(const vector<vector<bool>>& matr) {
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr.size(); j++) {
            if (i != j && matr[i][j] && matr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool IsTransitive(const vector<vector<bool>>& matr) {
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr.size(); j++) {
            if (matr[i][j]) {
                for (int k = 0; k < matr.size(); k++) {
                    if (matr[j][k] && !matr[i][k]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите размер матрицы: ";
    cin >> size;

    vector<vector<bool>> matrix(size, vector<bool>(size));
    InputMatrix(matrix);
    OutputMatrix(matrix, "Матрица отношения");

    cout << "Рефлексивность:     ";
    if (IsReflexive(matrix)) {
        cout << "присутствует\n";
    }
    else {
        cout << "отсутствует\n";
    }

    cout << "Симметричность:     ";
    if (IsSymmetric(matrix)) {
        cout << "присутствует\n";
    }
    else {
        cout << "отсутствует\n";
    }

    cout << "Кососимметричность: ";
    if (IsAntisymmetric(matrix)) {
        cout << "присутствует\n";
    }
    else {
        cout << "отсутствует\n";
    }

    cout << "Транзитивность:     ";
    if (IsTransitive(matrix)) {
        cout << "присутствует\n";
    }
    else {
        cout << "отсутствует\n";
    }

    return 0;
}