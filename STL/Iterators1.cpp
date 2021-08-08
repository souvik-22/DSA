#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 6};

    // for (int value : v)
    //     value++;

    // for (int value : v)
    //     cout << value << " ";// values of vector v are copied inside the variable 'value'

    for (int &value : v) //here value is the reference of every..
        value++;         //..values in vector v
    //so it increment every value of vector v by 1
    for (int value : v)
        cout << value << " ";
    cout << endl;
    vector<pair<int, int>> p = {{1, 2}, {2, 3}, {3, 4}};

    for (pair<int, int> &value : p)
    {
        value.second++; //= value.first+1;
        cout << value.first << " " << value.second << endl;
    }

    auto a = 1.04;
    cout << a << endl;
    for (auto &value : p)
    {
        value.second++; //= value.first+1;
        cout << value.first << " " << value.second << endl;
    }
}