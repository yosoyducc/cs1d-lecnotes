/*

Binary trees!

I give up, and 'Pedia has an Excellent article:
https://en.wikipedia.org/wiki/Binary_tree

Trees look like this:

      O
     / \
    O   O
   / \ / \
  O  O O  O

The first node is called the parent. The nodes that connect under it
are called the children.
The final Os at the end are called the leaves.


Types of trees:
* Full binary trees are trees where all nodes have 0-2 children.
* Perfect trees are where all nodes have two members and all leaves
  have the same depth/level.
* Complete tree is where all nodes are continuous from left to right (I DON'T KNOW HOW TO DEFINE THIS HELP)
* Some others IDK look at Wikipedia.
* There's also AVL trees, which are balanced trees. In AVL, all subtrees
  of every node should differ in height by no more than 1 to count as such.

Know pre-order, in-order, post-order, and level-order.
These are implemented in functions below.

*/

#include <iostream>
#include <queue>      /* used in level_order */
#include <stack>

using namespace std;

// sample node idk
struct Node {
    int data;
    Node *right, *left;
};


// The function that inserts into stack in a pre-order fashion
void pre_order(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> steck;

    steck.push(root);

    while (!steck.empty())
    {
        Node *node = steck.top();
        cout << node->data;
        steck.pop();

        if (node->right)
            steck.push(node->right);

        if (node->left)
            steck.push(node->left);
    }
}

void post_order(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> steck;
}

// NOT in lecture notes.
void level_order(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> queck;
    queck.push(root);
    while (!queck.empty())
    {
        //iuahsdiuh
        Node *node = queck.front();
        cout << node->data << " ";
        queck.pop();
        if (node->left)
            queck.push(node->left);
        if (node->right)
            queck.push(node->right);
    }
}

