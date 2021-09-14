#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void topView(Node *root)
{
    // vector<int> ans;
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mp)
    {
        cout << it.second << " ";
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->right->right = new Node(9);

    topView(root);

    /* 
            1
          /  \
         2    3
        /    / \
       4    5   6
       \   /     \
        7 8       9
    */

    return 0;
}