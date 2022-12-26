#include <iostream>

using namespace std;

struct Tree{
    int data;
    Tree *left;
    Tree *right;
};

Tree *leaf, *leaf2, *leaf3, *leaf4, *nodeBaru, *root=NULL;

bool isEmpty(){
    if(root == NULL){
        return true;
    }else{
        return false;
    }
}

void preOrder(Tree *current){
    if(current != NULL){
        cout << current->data<<" ";
        preOrder(current->left);
        preOrder(current->right);
    }
}

void inOrder(Tree *current){
    if(current != NULL){
        inOrder(current->left);
        cout << current->data<<" ";
        inOrder(current->right);
    }
}

void postOrder(Tree *current){
    if(current != NULL){
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data<<" ";
    }
}

Tree *tambahKiri(Tree *node, int data){
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right = NULL;
    if(node->left==NULL){
        node->left = nodeBaru;
    }else{
        node->left->left = nodeBaru;
    }

    return nodeBaru;
}
Tree *tambahKanan(Tree *node, int data){
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right = NULL;
    if(node->right==NULL){
        node->right = nodeBaru;
    }else{
        node->right->right = nodeBaru;
    }

    return nodeBaru;
}
Tree *buatTree(int data){
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right = NULL;
    root = nodeBaru;

    return nodeBaru;
}

int main()
{
    leaf = buatTree(6);
    leaf2 = tambahKiri(leaf, 5);
    leaf2 = tambahKanan(leaf, 7);

    cout << "Preorder = ";
    preOrder(leaf);
    cout << endl;
    cout << "Inorder = ";
    inOrder(leaf);
    cout << endl;
    cout << "Postorder = ";
    postOrder(leaf);
    return 0;
}
