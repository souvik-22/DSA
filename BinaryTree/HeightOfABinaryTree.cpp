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

int calcHeight(Node *root) // O(n), n = no. of nodes in binary tree
{
    if (root == NULL)
        return 0;

    int left_height = calcHeight(root->left);
    int right_height = calcHeight(root->right);
    return 1 + max(left_height, right_height);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << calcHeight(root);
    /* 
            1
          /  \
         2    3
        / \  / \
        4 5 6   7
    */

    return 0;
}