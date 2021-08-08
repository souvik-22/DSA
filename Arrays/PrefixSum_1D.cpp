#include <bits/stdc++.h>
using namespace std;
#define ll long long

int pf[100];
int a[100];

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    for (int i = 1; i <= n; i++) // 1 based indexing
    {
        cin >> a[i];
        pf[i] = a[i] + pf[i - 1];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << endl;
    }

    return 0;
}