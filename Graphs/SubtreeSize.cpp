/*
Calculating subtree size using DFS in O(N):
Given a tree, construct an adjray subSize[], where subSize[V] stores the size of subtree rooted at node V.
        1
       /
      2
     / \
    3   4 
subSize[1] = 4
subSize[2] = 3
subSize[3] = 1
subSize[4] = 1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001], subSize[100001];

int dfs(int node)
{
    vis[node] = 1;
    int curr = 1;

    for (int child : adj[node])
        if (vis[child] == 0)
        {
            curr += dfs(child);
        }

    return subSize[node] = curr;
}

int main()
{
    int n, a, b; // n = number of nodes

    cin >> n;
    for (int i = 1; i < n; i++) //for tree edges = n-1
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //call dfs(1) when 1 is root , if another node is root than pass that node
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Sub-tree size of node " << i << " is " << subSize[i] << endl;
    }
    return 0;
}