//https://www.spoj.com/problems/PPATH/

#include <bits/stdc++.h>
#define int long long int

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

using namespace std;

vector<int> adj[100001];
vector<int> primes;
int dist[100001], vis[100001];

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool isValid(int a, int b)
{
    int cnt = 0;
    while (a > 0)
    {
        if (a % 10 != b % 10)
            cnt++;

        a /= 10;
        b /= 10;
    }
    if (cnt == 1)
        return true;

    return false;
}

void buildGraph()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            int a = primes[i];
            int b = primes[j];
            if (isValid(a, b))
            {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : adj[curr])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1000; i <= 9999; i++)
    {
        dist[i] = -1;
        vis[i] = 0;
    }
    bfs(a);
    if (dist[b] == -1)
        cout << "Impossible";
    else
        cout << dist[b] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    buildGraph();
    for (int i = 1; i <= t; i++)
    {
        // printf("Case #%d: ", i);
        solve();
    }
    return 0;
}