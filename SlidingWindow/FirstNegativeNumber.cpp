/*
First Negative Number in every window size of K
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int A[1000], N, k;
    vector<long long> ans;
    list<int> li;
    long long i = 0, j = 0;

    while (j < N)
    {
        if (A[j] < 0)
            li.push_back(A[j]);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (li.size() == 0)
                ans.push_back(0);
            else
            {
                ans.push_back(li.front());
                if (A[i] == li.front())
                    li.pop_front();
            }
            i++;
            j++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
}
