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

int height(Node *root) // O(n)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root) // O(n * n)
{
    if (root == NULL)
        return true;
    if (isBalanced(root->left) == false)
        return false;

    if (isBalanced(root->right) == false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

bool isBalanced_new(Node *root, int *height) // O(n)
{
    if (root == NULL)
        return true;
    int lh = 0, rh = 0;
    if (isBalanced_new(root->left, &lh) == false)
        return false;
    if (isBalanced_new(root->right, &rh) == false)
        return false;

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
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

    /* 
            1        k = 0
          /  \
         2    3      k = 1
        / \  / \
        4 5 6   7    k = 2
    */

    //Height Balanced Tree
    if (isBalanced(root))
        cout << "Balanced Tree" << endl;
    else
        cout << "UnBalanced Tree" << endl;

    int height = 0;
    if (isBalanced_new(root, &height))
        cout << "Balanced Tree" << endl;
    else
        cout << "UnBalanced Tree" << endl;

    /* 
            1
           /
          2
         /
        3
    */
    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(3);

    if (isBalanced(root1))
        cout << "Balanced Tree" << endl;
    else
        cout << "UnBalanced Tree" << endl;

    height = 0;
    if (isBalanced_new(root1, &height))
        cout << "Balanced Tree" << endl;
    else
        cout << "UnBalanced Tree" << endl;
    return 0;
}