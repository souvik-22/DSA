#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int k, vector<int> &arr)
{
    int N = arr.size();
    int sum = 0;
    int i = 0, j = 0;
    int mx = INT_MIN;
    while (j < N)
    {
        sum += arr[j];
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            mx = max(mx, sum);
            j++;
            sum -= arr[i];
            i++;
        }
    }
    return mx;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maximumSumSubarray(k, arr);
}