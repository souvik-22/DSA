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
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int> temp;
        //v.push_back(vector<int>()); [ALTERNATIVE] {first create a empty vector then push elements into it}
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
            //v[i].push_back(x); [ALTERNATIVE]
        }
        v.push_back(temp);
    }
    v[0].push_back(10);         // 10 is added in 1st row
    v.push_back(vector<int>()); //Empty vector of size 0
    for (int i = 0; i < v.size(); i++)
    {
        printVec(v[i]);
    }
    cout << v[0][1];
}