#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

//FIND operation
int find(int v)
{
    if (parent[v] == -1)
        return v;
    return find(parent[v]);
}

void union_P(int fromP, int toP)
{
    fromP = find(fromP);
    toP = find(toP);
    parent[fromP] = toP;
}

bool isCyclic(vector<pair<int, int>> &edge_list)
{
    for (auto edge : edge_list)
    {
        int fromP = find(edge.first); //Find absolute parent
        int toP = find(edge.second);

        if (fromP == toP)
            return true;

        //UNION operation
        union_P(fromP, toP); // UNION of 2 sets
    }
    return false;
}

int main()
{
    int E, V;
    cin >> E >> V;

    parent.resize(V, -1);
    vector<pair<int, int>> edge_list;

    for (int i = 0; i < E; i++)
    {
        int from, to;
        cin >> from >> to;
        edge_list.push_back({from, to});
    }

    if (isCyclic(edge_list))
        cout << "Cycle is present[TRUE]\n";
    else
        cout << "Cycle is absent[FALSE]\n";

    return 0;
}