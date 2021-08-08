#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int c, vector<int> adj[], vector<bool> &vis, vector<int> &col)
{
    vis[v] = true;
    col[v] = c;
    for (int child : adj[v])
    {
        if (!vis[child])
        {
            if (dfs(child, c ^ 1, adj, vis, col) == false)
                return false;
        }
        else if (col[v] == col[child])
            return false;
    }
    return true;
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
    vector<bool> vis(n + 1, false);
    vector<int> col(n + 1);
    if (dfs(1, 0, adj, vis, col))
        cout << "Graph is bipartite i.e, the graph can be coloured using two colors" << endl;
    else
        cout << "Graph is not bipartite" << endl;
}