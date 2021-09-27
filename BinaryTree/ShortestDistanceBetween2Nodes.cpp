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
/*
Find the distance between two nodes in a binary tree. The distance
between two nodes is the minimum number of edges to be traversed
to reach one node from another.

Strategy:
1.Find the LCA
2.Find distance of n1(d1) & n2(d2) from LCA
3.Return (d1+d2)
*/

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL and right != NULL)
        return root;

    if (left == NULL && right == NULL)
        return NULL;

    if (left != NULL)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return dist;

    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
        return left;

    return findDist(root->right, k, dist + 1);
}

int distanceBetweenNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->right = new Node(6);

    /* Actual Binary Tree
            4      
          /  \
         9    5    
        / \    \
       1  7     6  
    */

    int n1 = 3, n2 = 6;
    cout << distanceBetweenNodes(root, n1, n2) << endl;
    return 0;
}
