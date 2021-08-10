/*
Single Source Shortest Path using BFS.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001], dist[100001];

void bfs(int root, int d)
{
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    dist[root] = d;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int child : adj[temp])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[temp] + 1;
            }
        }
    }
}

int main()
{
    int n, e, a, b; // n = number of nodes, e = number of edges

    cin >> n >> e;
    for (int i = 1; i <= e; i++) 
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(1, 0);//call bfs on root

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node " << i << " from root(1) is " << dist[i] << endl;
    }
    return 0;
}