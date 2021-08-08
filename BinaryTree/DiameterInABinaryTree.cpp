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

/*
Diameter of a tree:
Number of nodes in the longest path between any 2 leaves.
*/

int calcDiameter(Node *root) //  O(n) * O(n) = O(n^2)
{
    if (root == NULL)
        return 0;

    int left_height = calcHeight(root->left);
    int right_height = calcHeight(root->right);

    int currDiameter = left_height + right_height + 1;

    int left_diameter = calcDiameter(root->left);
    int right_diameter = calcDiameter(root->right);

    return max(currDiameter, max(left_diameter, right_diameter));
}

// O(n)
int calcDiameter1(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;

    int lDiameter = calcDiameter1(root->left, &lh);
    int rDiameter = calcDiameter1(root->right, &rh);

    int currDiameter = lh + rh + 1;

    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
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

    cout << calcDiameter(root) << "\n"; // O(n^2)

    //Diameter of Binary Tree  -  Optimized  -  O(n)
    int height = 0;
    cout << calcDiameter1(root, &height);

    /* 
            1
          /  \
         2    3
        / \  / \
       4  5 6   7
    */

    return 0;
}