#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here += a[i];
        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            start = i + 1;
        }
    }
    cout << max_so_far << endl;
    cout << start << " " << end << endl;
    /* 
    int max_so_far = a[0];
    int curr_max = a[0];
    for(int i = 1; i < n; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
    */
}