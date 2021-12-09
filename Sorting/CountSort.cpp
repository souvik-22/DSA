#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr)
{
    int n = arr.size();
    int k = arr[0]; // k stores the value of maximum element.
    // k = *max_element(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    vector<int> count(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 4, 1, 6, 4, 3};

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}