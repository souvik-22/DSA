#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> ans;
    queue<int> q;
    void bfs(int V, vector<int> adj[])
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        visited[0] = true;
        //ans.push_back(0);
        q.push(0);
        while (!q.empty())
        {
            int s = q.front();
            ans.push_back(s);

            q.pop();

            for (int v : adj[s])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        bfs(V, adj);
        return ans;
    }
    /* for multiple components
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<int> vis(V + 1, 0);

        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return bfs;
    }
    */
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); //comment this line for directed graph.
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
