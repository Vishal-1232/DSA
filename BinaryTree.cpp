// WAP TO DEMONSTRATE THE IMPLEMENTATION OF BINARY TREE
#include <iostream>
#include <queue> // for level order traversal
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    node(int e)
    {
        data = e;
        left = NULL;
        right = NULL;
    }
};

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        cout << temp->data << " ";
        q.pop();
    }
}

int maxDepth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);

    return (1 + max(left_height, right_height));
}

int dfs_height(node *root) // for helping isbalanced function
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = dfs_height(root->left);

    if (left_height == -1)
    {
        return -1;
    }

    int right_height = dfs_height(root->right);

    if (right_height == -1)
    {
        return -1;
    }

    if (abs(left_height - right_height) > 1)
    {
        return -1;
    }

    return (1 + max(left_height, right_height));
}

bool isBalanced(node *root)
{
    return dfs_height(root) != -1; // only returns true if height != -1 else return false
}

int height(node *root, int &maxi) // helper function for diameter function
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(root->left, maxi);
    int right_height = height(root->right, maxi);

    maxi = max(maxi, (left_height + right_height));

    return 1 + max(left_height, right_height);
}

int diameter(node *root) // diameter of tree is the longest path between two nodes  ,   path does not need to pass via root
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

void MorrisTraversal(node *root)
{
    node *curr = root;
    node *predecessor = NULL;

    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr; // Make current as the right child of its
                curr = curr->left;         //inorder predecessor
            }
            else
            {
                predecessor->right = NULL; // Revert the changes made in the 'if' part to
                cout << curr->data << " "; //restore the original tree i.e., fix the right
                curr = curr->right;        //child of predecessor
            }
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    // dfs
    cout << "Preorder : ";
    preorder(root);
    cout << endl;

    cout << "Inorder : ";
    inorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    // bfs
    cout << "Level Order Traversal : ";
    levelorder(root);
    cout << endl;

    // max height of tree
    cout << "Max height of tree : " << maxDepth(root) << endl;

    // check for balanced tree
    if (isBalanced(root))
    {
        cout << "Yes the given tree is balanced ";
    }
    else
    {
        cout << "No the given tree is not balanced ";
    }
    cout << endl;

    // diameter of tree
    cout << "Diameter of tree : " << diameter(root) << endl;

    // Morris Traversal --> O(1) space complexity,O(N) time complexity
    cout << "Morris Traversal O(1) space complexity,O(N) time complexity" << endl;
    MorrisTraversal(root);

    return 0;
}