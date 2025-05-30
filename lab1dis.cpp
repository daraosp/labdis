#include <iostream>
#include <vector>


#define endl "\n"

using namespace std;
//ijji
struct Element {
    char first;     // i - четн 
    char second;    // j - нечет
    char third;     // j - нечет
    char fourth;    // i - чет
};

void InputArray(vector<Element>& arr, int size)
{
    Element elem_a;
    for (int i = 0; i < size; i++)
    {
        cout << "Input Elem " << i + 1 << ": ";
        string el_arr;
        cin >> el_arr;

        if (el_arr.length() == 4 &&
            (el_arr[0] >= '0' && el_arr[0] <= '9' && ((el_arr[0] - '0') % 2 == 0)) &&
            (el_arr[1] >= '0' && el_arr[1] <= '9' && ((el_arr[1] - '0') % 2 != 0)) &&
            (el_arr[2] >= '0' && el_arr[2] <= '9' && ((el_arr[2] - '0') % 2 != 0)) &&
            (el_arr[3] >= '0' && el_arr[3] <= '9' && ((el_arr[3] - '0') % 2 == 0)))
        {
            elem_a.first = el_arr[0];
            elem_a.second = el_arr[1];
            elem_a.third = el_arr[2];
            elem_a.fourth = el_arr[3];
            arr.push_back(elem_a);
        }
        else
        {
            cout << "Error Input" << endl;
            i--;
        }
    }
    cout << endl;
}

void OutputArray(vector<Element>& arr)
{
    cout << " ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].first << arr[i].second << arr[i].third << arr[i].fourth;
        if (i + 1 != arr.size()) cout << ", ";
    }
    cout << " " << endl;
}

void RemUniqueArray(vector<Element>& arr)
{
    vector<Element> UniqueArray;

    for (int i = 0; i < arr.size(); i++)
    {
        bool unique = true;

        for (size_t j = 0; j < UniqueArray.size(); j++)
        {
            if (arr[i].first == UniqueArray[j].first &&
                arr[i].second == UniqueArray[j].second &&
                arr[i].third == UniqueArray[j].third &&
                arr[i].fourth == UniqueArray[j].fourth)
            {
                unique = false;
                break;
            }
        }

        if (unique) {
            UniqueArray.push_back(arr[i]);
        }
    }

    arr.clear();
    for (int i = 0; i < UniqueArray.size(); i++)
    {
        arr.push_back(UniqueArray[i]);
    }
}

void UnionArray(vector<Element>& arr1, vector<Element>& arr2, vector<Element>& arr)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        arr.push_back(arr1[i]);
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        arr.push_back(arr2[i]);
    }

    RemUniqueArray(arr);
}

void CrossingArrays(vector<Element>& arr1, vector<Element>& arr2, vector<Element>& arr)
{
    bool cross = true;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i].first == arr2[j].first &&
                arr1[i].second == arr2[j].second &&
                arr1[i].third == arr2[j].third &&
                arr1[i].fourth == arr2[j].fourth)
            {
                arr.push_back(arr1[i]);
                cross = false;
            }
        }
    }

    if (cross) cout << "The intersection not exist" << endl;
}

void AdditionArray(vector<Element>& arr1, vector<Element>& arr2, vector<Element>& arr)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        bool add = true;

        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i].first == arr2[j].first &&
                arr1[i].second == arr2[j].second &&
                arr1[i].third == arr2[j].third &&
                arr1[i].fourth == arr2[j].fourth)
            {
                add = false;
                break;
            }
        }

        if (add) arr.push_back(arr1[i]);
    }
}

void DifArray(vector<Element>& arr1, vector<Element>& arr2, vector<Element>& arr)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        bool dif = true;
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i].first == arr2[j].first &&
                arr1[i].second == arr2[j].second &&
                arr1[i].third == arr2[j].third &&
                arr1[i].fourth == arr2[j].fourth)
            {
                dif = false;
                break;
            }
        }

        if (dif) arr.push_back(arr1[i]);
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        bool dif = true;
        for (int j = 0; j < arr1.size(); j++)
        {
            if (arr2[i].first == arr1[j].first &&
                arr2[i].second == arr1[j].second &&
                arr2[i].third == arr1[j].third &&
                arr2[i].fourth == arr1[j].fourth)
            {
                dif = false;
                break;
            }
        }

        if (dif) arr.push_back(arr2[i]);
    }
}

int main()
{
    cout << " even digit, odd, odd, even\n" << endl;
        

    int size_a1 = 0, size_a2 = 0;
    vector<Element> arr1;
    vector<Element> arr2;

    cout << "Input size first array: ";
    cin >> size_a1;
    cout << endl;
    InputArray(arr1, size_a1);

    cout << "Input size second array: ";
    cin >> size_a2;
    cout << endl;
    InputArray(arr2, size_a2);

    RemUniqueArray(arr1);
    cout << "Elements first array: ";
    OutputArray(arr1);

    RemUniqueArray(arr2);
    cout << "Elements second array: ";
    OutputArray(arr2);

    cout << endl;
    vector<Element> arr_union;
    UnionArray(arr1, arr2, arr_union);
    cout << "Union: ";
    OutputArray(arr_union);

    vector<Element> arr_intersection;
    cout << "Intersection: ";
    CrossingArrays(arr1, arr2, arr_intersection);
    OutputArray(arr_intersection);

    vector<Element> arr_addition12;
    AdditionArray(arr1, arr2, arr_addition12);
    cout << "Array1 \\ Array2: ";
    OutputArray(arr_addition12);

    vector<Element> arr_addition21;
    AdditionArray(arr2, arr1, arr_addition21);
    cout << "Array2 \\ Array1: ";
    OutputArray(arr_addition21);

    vector<Element> arr_difference;
    DifArray(arr1, arr2, arr_difference);
    cout << "Symm diff: ";
    OutputArray(arr_difference);

    return 0;
}