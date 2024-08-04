#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return root->height;
}

int getBalance(Node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node *insert(Node *root, int key)
{
    if (!root)
    {
        return new Node(key);
    }

    if (key < root->data)
    { // left side insertion
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    { // right side insertion
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // duplicates elements are not allowed
    }

    // update height of root
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balancing check
    int balance = getBalance(root);

    // Left Left case (L-L Rotation): Right Rotation (Top)
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    // Right Right case (R-R Rotation): Left Rotation (Top)
    else if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }
    // Left Right case (L-R Rotation): Left Rotation (Middle), Right Rotation(Top)
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Left case (R-L Rotation): Right Rotation (Middle), Left Rotation(Top)
    else if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No unbalancing
    else
    {
        return root;
    }
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }

    if (key < root->data)
    { // left side
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    { // right side
        root->right = deleteNode(root->right, key);
    }
    else
    { // Node to be deleted is found
        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // one child exist
        else if (root->left && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exist
        else
        {
            // find right side smallest element or left side largest element, we are going with right side smallest
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            // replace root data with right smallest element data
            root->data = curr->data;
            // delete that right smallest node
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check balancing
    int balance = getBalance(root);
    // left side unbalanced
    if (balance > 1)
    {
        // LL case
        if (getBalance(root->left) >= 0)
        {
            return rightRotation(root);
        }
        // LR case
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // Right side unbalanced
    else if (balance < -1)
    {
        // RR case
        if (getBalance(root->right) <= 0)
        {
            return leftRotation(root);
        }
        // RL case
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    // already balanced
    else
    {
        return root;
    }
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    inorder(root);
    return 0;
}