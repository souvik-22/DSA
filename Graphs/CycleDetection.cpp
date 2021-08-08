#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &vis, int parent)
{
    vis[node] = true;
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, adj, vis, node))
                return true;
        }
        else if (child != parent)
            return true;
    }
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (dfs(1, adj, vis, -1))
        cout << "Cycle is there" << endl;
    else
        cout << "No Cycle is there" << endl;
}