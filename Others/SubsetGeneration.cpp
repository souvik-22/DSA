#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSubsets(vector<int> num) //O(n * 2^n)
{
    int size = num.size();       // size = 3 num = {1,2,3}
    int subsetNum = (1 << size); //subsetNum = 8

    vector<vector<int>> allSubsets;
    for (int subsetMask = 0; subsetMask < subsetNum; subsetMask++) //O(2^n)
    {
        vector<int> subset;
        for (int i = 0; i < size; i++) //O(n)
        {
            if ((subsetMask & (1 << i)) != 0)
            {
                subset.push_back(num[i]);
            }
        }
        allSubsets.push_back(subset);
    }
    return allSubsets;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }
    vector<vector<int>> subsets = getSubsets(num);
}