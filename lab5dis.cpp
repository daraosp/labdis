#include <iostream>
#include <vector>
using namespace std;

void InputMatrix(vector<vector<bool>>& matr) {
    cout << "Введите матрицу смежности (0/1): " << endl;
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

void FindMatrDos(vector<vector<bool>>& matrdos) {
    int n = matrdos.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrdos[i][j] && matrdos[i][k] && matrdos[k][j]) {
                    matrdos[i][j] = true;
                
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int versh;
    cout << "Введите количество вершин: ";
    cin >> versh;

    vector<vector<bool>> matr(versh, vector<bool>(versh));
    InputMatrix(matr);

    vector<vector<bool>> matrdos = matr;
    FindMatrDos(matrdos);

    OutputMatrix(matr, "Матрица смежности:");
    OutputMatrix(matrdos, "Матрица достижимости:");

    return 0;
}