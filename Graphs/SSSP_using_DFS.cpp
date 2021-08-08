/*
Single Source Shortest Path(on Trees only) using DFS.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &dist, int d)
{
    vis[node] = true;
    dist[node] = d;
    for (int v : adj[node])
    {
        if (!vis[v])
        {
            dfs(v, adj, vis, dist, d + 1);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int node;
    cin >> node;
    vector<bool> vis(n + 1, false);
    vector<int> dist(n + 1);
    dfs(node, adj, vis, dist, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << "Dist. of " << i << " from " << node << " is: " << dist[i] << endl;
    }
}