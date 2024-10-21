/*

Binary trees again.

This will be on quiz & the lab lol.

*/


struct Node {
    int data;
    Node *right, *left;
};

// In-order successor
// The smallest node in the right subtree of the node to be deleted

Node *smallest(Node *node)
{
    // Can be optimized. Test if node is nul, return if true.
    // Otherwise same code but without current && comp in while.
    Node *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// In-order predecessor
// The highest node in the left subtree of the node to be deleted.
// I think this one is in the lecture notes anyway.