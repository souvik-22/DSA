#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
vector<int> g[N];

bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    for (int v : g[u])
    {
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main()
{
    int n, m, u, v; //n->nodes, m->edges
    cin >> n >> m;

    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); //comment this line for directed edges
    }

    dfs(1);

    if (vis[5])
        cout << "Yes we can reach to 6 from 1";
    else
        cout << "No we can't reach";

    return 0;
}
/*
6 nodes, 5 edges

1---2---6  4---5
 \ /
  3

  property:
  undirected graph

1--->2--->6  ==> directed graph

  2 forests
  forest1: <1,2,3,6>
  forest2: <4,5>

  forest1 has a cycle: [1,2,3]
  forest1 is not a tree
  forest2 is a tree

  every tree is a graph
  trees do not have any cycles
  there is one forest in a tree ==> N nodes in a tree -> N-1 edges

  can we reach to 4 from 1 -> no ==> connectivity problem(x and y)
*/