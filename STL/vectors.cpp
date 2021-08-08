#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v) //passing reference of the vector
{
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        //v.size() -> O(1)
        cout << v[i] << " ";
    }
    v.push_back(2);
    cout << endl;
}

void printVecString(vector<string> &v)
{
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        //v.size() -> O(1)
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(6);
    //vector<int> v2 = v;  O(n) for copying
    vector<int> &v2 = v; //reference
    v2.push_back(5);     //5 is added in v2 as well as v
    printVec(v);
    printVec(v);
    printVec(v2);

    vector<string> ss;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        ss.push_back(s);
    }
    printVecString(ss);
}