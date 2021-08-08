#include <bits/stdc++.h>
using namespace std;

void printVec(vector<pair<int, int>> &v)
{
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        //v.size() -> O(1)
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

int main()
{
    vector<pair<int, int>> v; //= {{1, 2}, {2, 3}, {3, 4}};
    //printVec(v);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        //v.push_back(make_pair(x, y));
    }
    printVec(v);
}