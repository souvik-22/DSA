/*

Algorithm:
For each node, compute:
1. Node Val
2. Max path through left child + node val
3. Max path through right child + node val
4. Max path through left child + node val + Max path through right child

*/

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

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int lmax = maxPathSumUtil(root->left, ans);
    int rmax = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + lmax + rmax),
                      max(root->data + lmax, root->data + rmax));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + lmax, root->data + rmax));

    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
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

    cout << maxPathSum(root) << endl;

    /* 
            1
          /  \
        -12   3
        /    / \
       4    5  -6
    */

    struct Node *root1 = new Node(1);
    root1->left = new Node(-12);
    root1->right = new Node(3);

    root1->left->left = new Node(4);
    root1->right->left = new Node(5);
    root1->right->right = new Node(-6);

    cout << maxPathSum(root1) << endl;

    return 0;
}