/*
//https://www.youtube.com/watch?v=FQLPNQppBNs&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=15
What is Diameter of Tree?
->It is defined as the longest path between any 2 nodes in the tree.
->We would run DFS, N times
In each iteration, we would set ith node as root and find distance of farthest node. 
Running Time : O(N^2)

Better approach:
We can find diameter in only 2 DFS run.
Take any arbitrary node as root and run dfs from it and find the farthest node, let this node be x.
Run a dfs from node x and find the maximum distance from this node to any other node, this distance is diameter.
*/

#include <bits/stdc++.h>
using namespace std;

int maxDist, maxNode;

void dfs(int node, int dist, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    if (dist > maxDist)
    {
        maxDist = dist;
        maxNode = node;
    }
    for (int child : adj[node])
    {
        if (!vis[child])
            dfs(child, dist + 1, adj, vis);
    }
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
    maxDist = -1;
    dfs(1, 0, adj, vis);

    for (int i = 0; i <= n; i++)
        vis[i] = false;

    maxDist = -1;
    dfs(maxNode, 0, adj, vis);

    cout << maxDist << endl;
}