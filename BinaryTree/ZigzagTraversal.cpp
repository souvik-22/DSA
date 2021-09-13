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

void zigzagLevelOrder(Node *root)
{
    vector<vector<int>> ans;

    if (!root)
    {
        cout << "Tree is Empty";
        return;
    }

    queue<Node *> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            temp.push_back(curr->data);
            // if (i == 0)
            //     cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (cnt % 2 == 0)
        {
            ans.push_back(temp);
        }
        else
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        cnt++;
    }

    //ZigZag Traversal
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
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

    zigzagLevelOrder(root);

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