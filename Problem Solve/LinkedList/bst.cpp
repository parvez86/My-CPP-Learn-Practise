#include <iostream>

using namespace std;

class BST{
    struct node {
       int data;
        node *left;
        node *right;
    };
    node* root;
    node* insert(node* root, int data)
    {
        if(root == NULL){
            root = new node;
            root->data = data;
            root->left = root->right = NULL;
        }else{
            if(data<=root->data) root->left = insert(root->left, data);
            else root->right = insert(root->right, data);
        }
        return root;
    }

    //
    node* makeEmpty(node* root){
        if(root == NULL) return NULL;
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;

        return NULL;
    }

    node* search(node* root, int data){
        if(root== NULL || root->data == data) return root;
        if(data<= root->data) return search(root->left, data);
        else return search(root->right, data);
    }

    node* searchMin(node* root){
        if(root==NULL || root->left== NULL) return root;
        return searchMin(root->left);
    }

    node* searchMax(node* root){
        if(root==NULL || root->right== NULL) return root;
        return searchMax(root->right);
    }

    node* remove(node* root, int data){
        node *temp;
        if(root == NULL) return NULL;
        else if (data < root->data) root->left = remove(root->left, data);
        else if(data > root->data) root->right = remove(root->right, data);

        // if the node has both child
        else if(root->left && root->right){
            temp = searchMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, root->data);
        }
        else{
            temp = root;
            if(root->left==NULL) root = root->right;
            else if(root->right == NULL) root = root->left;
            delete temp;
        }

        return root;
    }

    // in-order sequence:
    //      left> root> right
    void inorder(node* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<< root->data<< " ";
        inorder(root->right);
    }

    // pre-order sequence:
    //      root> left> right
    void preorder(node* root){
        if(root == NULL) return;
        cout<< root->data<< " ";
        preorder(root->left);
        preorder(root->right);
    }

    // post-order sequence:
    //      left > right> root
    void postorder(node* root)
    {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout<< root->data<< " ";
    }
public:
    BST(){
        root = NULL;
    }
    ~BST(){
        root = makeEmpty(root);
    }
    void insertNode(int data){
        root = insert(root, data);
    }
    node* findNode(int data){
        return search(root, data);
    }

    void findMinNode(int data){
        node* min_node = searchMin(findNode(data));
        cout<< "The min node of "<< data<< ": "<< min_node->data<< endl;
    }

    void findMaxNode(int data){
        node* max_node = searchMax(findNode(data));
        cout<< "The max node of "<< data<< ": "<< max_node->data<< endl;
    }

    void deleteNode(int data){
        root = remove(root, data);
    }

    void preOrderDisplay(){
        cout<< "The nodes are (in pre-order): ";
        preorder(root);
        cout<< endl;
    }
    void inOrderDisplay(){
        cout<< "The nodes are (in in-order): ";
        inorder(root);
        cout<< endl;
    }
    void postOrderDisplay(){
        cout<< "The nodes are (in post-order): ";
        postorder(root);
        cout<< endl;
    }
};

int main()
{
    BST tree;
    tree.insertNode(20);
    tree.insertNode(25);
    tree.insertNode(15);
    tree.insertNode(30);
    tree.insertNode(35);
    tree.insertNode(10);
    tree.insertNode(18);
    tree.insertNode(22);
    tree.preOrderDisplay();
    tree.inOrderDisplay();
    tree.postOrderDisplay();

    tree.findMinNode(25);
    tree.findMaxNode(25);

    tree.deleteNode(25);
    tree.inOrderDisplay();
}
