//https://www.hackerearth.com/practice/notes/iterative-tree-traversals/

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

void inorder(Node *root) // Left - Root - Right
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    vector<int> ans;
    stack<Node *> s;

    Node *cur = root;
    while (cur != NULL || s.empty() == false)
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        ans.push_back(cur->data);
        cur = cur->right;
    }

    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}

void preorder(Node *root) // Root - Left - Right
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    stack<Node *> st;
    vector<int> ans;
    st.push(root);
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (st.empty() == false)
    {
        // Pop the top item from stack and print it
        Node *node = st.top();
        ans.push_back(node->data);
        st.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}

void postorder(Node *root) // Left - Right - Root
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<Node *> st;
    vector<int> ans;
    Node *prev = NULL;
    do
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        while (root == NULL && !st.empty())
        {
            root = st.top();
            if (root->right == NULL || root->right == prev)
            {
                ans.push_back(root->data);
                st.pop();
                prev = root;
                root = NULL;
            }
            else
                root = root->right;
        }
    } while (!st.empty());
    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    /* 
            1
          /  \
          2   3
         / \
         4 5  
    */
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}
/*
Post Order Traversal:

Post order traversal is the trickiest one, out of all the three traversals. 
However post order traversal is important to understand because of the following 2 use cases

> * Tree deletion: In order to free up allocated memory of all nodes in a 
tree, the nodes must be deleted in the order where the current node is 
deleted when both of its left and right sub-trees are deleted. This can 
be done using post-order traversal only.

> * It is also used in evaluating Post-fix or Reverse Polish Notation.

The problem with post-order traversal is that in the previous two cases 
when a node was popped of from the stack, then it was finally removed and 
was not accessed again. However in case of post-order the node needs to 
be accessed from the stack twice, and is deleted only in the second access.

First time we find a node, we push it on to the stack, the second time 
we examine it from the stack to go to it's right child and then finally 
after visiting both the right sub-tree and the left-subtree we remove the 
node from the stack. So a node stays in the stack as long as it's sub-trees 
have not been visited.

> Since, a node has to be visited(printed in the trivial case) only after 
it's left and right child have been visited, we print a node's value after 
we have visited the left child followed by the right child. The property 
that is exploited in this implementation is that the the parent node will 
always be visited just after visiting it's right child.

After visiting the left child, when we come to the parent node in the stack 
if the right child is NULL, then we can straight away print the node, but 
if it's not NULL then we have to check whether the previous node which was 
printed is it's right child. If it's the right child then we can visit the 
current node, otherwise the right child has not been visited and we must 
proceed with the right child.

Hence in this traversal, we have to use a previous pointer, only then will 
we able to correctly traverse the node. Otherwise we do not know when the 
right child has been visited or not.

> 1. Start with the root node.

> 2. Store the node in the stack, and visit it's left child.

> 3. Repeat step 1 while node is not NULL, if it's NULL:

> * Pick the top most node from the stack.

> * If it's right child is NULL, then print the node and set prev 
pointer to this node

> * If it's not NULL, check whether the right child is equal to prev 
pointer, if it is then print the node, else repeat step 1 with the right child

> * In this step, if you print the node then current is made equal to 
NULL and this sub-loop is repeated untill stack is not empty and current is NULL

> 4. Since the root node remains in the stack till the end, the terminating 
condition is untill stack is empty
*/