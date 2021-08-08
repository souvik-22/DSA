#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
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
    int N;
    cin >> N;
    vector<int> v[N]; //2D array  //v[0] is one vector
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
    {
        printVec(v[i]);
    }
    cout << v[0][1];
}