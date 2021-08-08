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
Given a binary tree, flatten it into linked list in-place.
After flattening, left of each node should point to NULL and
right should contain next node in preorder sequence.
(It's NOT allowed to use other data structures)
*/

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->left != NULL)
    {
        flatten(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    /* Actual Binary Tree
            4      
          /  \
         9    5    
        / \    \
       1  3     6  
    */
    /*  Flatten Binary Tree
        4
         \
          9
           \
            1
             \
              3
               \
                5
                 \
                  6
    */
    inorderPrint(root);
    cout << endl;
    flatten(root);
    inorderPrint(root);
    cout << endl;
    return 0;
}