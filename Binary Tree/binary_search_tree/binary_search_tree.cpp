#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root, int target){
    if(root==NULL){
        return false;
    }
    if(target == root->data){
        return true;
    }

    if(target < root->data){
        return search(root->left,target);
    }
    return search(root->right,target);
}

Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }

    if(root->data > val){
        root->left = insertNode(root->left,val);
    }else{
        root->right = insertNode(root->right,val);
    }

    return root;
}

Node* deleteNode(Node*root, int target){
    if(!root){
        return NULL;
    }

    if(root->data > target){
        root->left = deleteNode(root->left,target);
        return root;
    }else if(root->data < target){
        root->right = deleteNode(root->right,target);
        return root;
    }else{ // target node == root node
        // case 1 : Node to be deleted is a leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2 : Node to be deleted has one child
        else if(root->right == NULL){ // only left child exist
            Node* temp = root->left;
            delete root;
            return temp;
        }else if(root->left == NULL){ // only right child exist
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // case 3: Node to be deleted have two child
        else{
            // find the greatest element from left
            Node* parent = root;
            Node* child = root->left;

            while(child->right){
                parent = child;
                child = child->right;
            }

            if(root != parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }else{
                child->right = parent->right;
                delete root;
                return child;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 7, 4, 1, 6, 8};
    Node *root = NULL;
    for (int i = 0; i < 6; i++)
    {
        root = insertNode(root, arr[i]);
    }

    //inorder(root);
    cout<<search(root,8);
    return 0;
}