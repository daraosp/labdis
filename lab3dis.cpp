#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int PAIRSIZE = 2;

void InputArray(vector<char>& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Элемент " << i + 1 << " из множества ";
        char ch = 0;
        cin >> ch;
        if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
            array.push_back(ch);
        }
        else {
            cout << "Некорректный символ" << endl;
            i--;
        }
    }
    cout << endl;
}

void InputRelation(vector<vector<char>>& relation, int size, vector<char>& array1, vector<char>& array2) {
    for (int i = 0; i < size; i++) {
        cout << "Пара " << i + 1 << endl;
        vector<char> currentpair;
        for (int j = 0; j < PAIRSIZE; j++) {
            cout << "Элемент " << j + 1 << " из отношения ";
            char ch = 0;
            cin >> ch;

            if (j == 0) {
                if (find(array1.begin(), array1.end(), ch) == array1.end()) {
                    cout << "Элемента нет в первом множестве " << endl;
                    j--;
                    continue;
                }
            }
            else {
                if (find(array2.begin(), array2.end(), ch) == array2.end()) {
                    cout << "Элемента нет во втором множеств" << endl;
                    j--;
                    continue;
                }
            }
            currentpair.push_back(ch);
        }
        relation.push_back(currentpair);
        cout << endl;
    }
    cout << endl;
}

void OutputArray(vector<char>& array) {
    cout << "";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i + 1 != array.size()) cout << ", ";
    }
    cout << "" << endl;
}

void OutputRelation(vector<vector<char>>& relation) {
    cout << "";
    for (int i = 0; i < relation.size(); i++) {
        cout << "(";
        for (int j = 0; j < relation[i].size(); j++) {
            cout << relation[i][j];
            if (j == 0) cout << ", ";
        }
        cout << ")";
        if (i + 1 != relation.size()) cout << ", ";
    }
    cout << "" << endl;
}

bool IsRelationFunction(vector<vector<char>>& relation, vector<char>& array1) {
    if (relation.size() != array1.size()) {
        return false;
    }

    sort(relation.begin(), relation.end(), [](const vector<char>& a, const vector<char>& b) {
        return a[0] < b[0];
        });

    for (int i = 0; i < relation.size() - 1; i++) {
        if (relation[i][0] == relation[i + 1][0]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size1 = 0;
    cout << "Количество элементов в первом множестве ";
    cin >> size1;
    cout << endl;
    vector<char> array1;
    InputArray(array1, size1);
    sort(array1.begin(), array1.end());
    array1.erase(unique(array1.begin(),array1.end()), array1.end());

    int size2 = 0;
    cout << "Количество элементов во втором множестве ";
    cin >> size2;
    cout << endl;
    vector<char> array2;
    InputArray(array2, size2);
    sort(array2.begin(), array2.end());
    array2.erase(unique(array2.begin(), array2.end()), array2.end());

    int relsize = 0;
    cout << "Количество пар в отношении ";
    cin >> relsize;
    cout << endl;
    vector<vector<char>> relation;
    InputRelation(relation, relsize, array1, array2);

    cout << "Первое множество ";
    OutputArray(array1);

    cout << "Второе множество ";
    OutputArray(array2);

    cout << "Отношение ";
    OutputRelation(relation);

    if (IsRelationFunction(relation, array1)) {
        cout << "Данное отношение ЯВЛЯЕТСЯ функцией" << endl;
    }
    else {
        cout << "Данное отношение НЕ является функцией" << endl;
    }
    return 0;
}
