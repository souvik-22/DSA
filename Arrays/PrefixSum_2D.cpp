#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 10e3 + 10;
int ar[N][N];
int pf[N][N];

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    for (int i = 1; i <= n; i++) //1 based indexing
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
            pf[i][j] = ar[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1] << endl;
    }
    return 0;
}
