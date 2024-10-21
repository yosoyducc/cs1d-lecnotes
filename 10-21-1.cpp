/*

IDK LOL

To find the array representation of a node in a binary tree, use (where i is index):

2 * i + 1    // for left nodes to find child index
2 * i + 2    // for right nodes to find child index
(i - 1) / 2  // to find the parent node index (remainder ignored obviously)

This works best for full and perfect trees. It can be implemented for other
tree types, but this is the two it works best with.



       (50)
      /    \
   (27)     (70)
  /   \     /   \
(25) (40) (60) (80)

Array representation:

.----------------------------------.
| 50 | 27 | 70 | 25 | 40 | 60 | 80 |
*----------------------------------*

*/


class Node {
public:
    int value;
    Node *left, *right;

    Node(int value)
    {
        this->value = value;
        left = right = nullptr;
    }
};

class BST {
    Node *root;

public:
    BST() { root = nullptr; }
    ~BST() { destroy(root); }

    void destroy(Node *node)
    {
        if (node->left)
            destroy(node->left);
        if (node->right)
            destroy(node->right);

        delete node;
    }

    bool insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        // temporary pointer used to traverse the binary tree to determine
        // where to place the value
        Node *aux = root;
        for (;;)
        {
            // Binary trees may not have duplicate values
            // INFO: This is not in the lecture notes! Remember this!
            if (newNode->value == aux->value)
                return false;

            if (newNode->value < aux->value)
            {
                if (aux->left == nullptr)
                {
                    aux->left = newNode;
                    return true;
                }

                aux = aux->left;
            }

            if (newNode->value > aux->value)
            {
                if (aux->right == nullptr)
                {
                    aux->right = newNode;
                    return true;
                }

                aux = aux->right;
            }
        }
    }

    bool contains(int value)
    {
        /*if (root == nullptr)
            return false;*/

        // we check for the above condition here
        Node *aux = root;
        while (aux)
        {
            if (value < aux->value)
            {
                aux = aux->left;
            }
            else if (value > aux->value)
            {
                aux = aux->right;
            }
            else
                return true;
        }

        return false;
    }
};
