#include <bits/stdc++.h>

using namespace std;

class BT{
public:
    struct node{
        int data;
        struct node *left_child;
        struct node *right_child;
    };

    // functions
    struct BT::node* new_node(int);
    struct BT::node* insert_node(struct BT::node*, int);
    struct BT::node* delete_node(struct BT::node*, int);
    // aditional
    struct BT::node* search_node(struct BT::node*, int);
    struct BT::node* find_minimum(struct BT::node*);

    // print tree
    void inOrder(struct BT::node*);
    void preOrder(struct BT::node*);
    void postOrder(struct BT::node*);
};


struct BT::node* BT::new_node(int data)
{
    struct BT::node *p = new node;
    p->data = data;
    p->left_child = p->right_child = NULL;

    return p;
};


struct BT::node* BT::insert_node(struct BT::node* root, int data){
    // add new node to the corresponding leaf node
    if(root==NULL) return new_node(data);

    // tree
    if(root->data >= data) root->left_child = insert_node(root->left_child, data);
    else root->right_child = insert_node(root->right_child, data);

    return root;
};


struct BT::node* BT::delete_node(struct BT::node* root, int data){

    // maintain the tree until the value is found
    if(root==NULL) return NULL;
    else if(root->data > data) root->left_child = delete_node(root->left_child, data);
    else if(root->data < data) root->right_child = delete_node(root->right_child, data);

    // if value is found
    else{
        // if delete node has no child
        if(root->left_child == NULL && root->right_child == NULL){
            delete(root);
            return NULL;
        }

        // has single child
        else if(root->left_child == NULL || root->right_child == NULL){
            struct BT::node* temp;
            (root->left_child==NULL)? temp=root->right_child:temp = root->left_child;
            delete(root);
            return temp;
        }
        // has both child
        else{
            // find nearest child from right branch
            // replace the child to the delete node
            // re-build the (right) branch
            struct BT::node* temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete_node(root->right_child, temp->data);
        }
    }
    return root;
};


struct BT::node* BT::search_node(struct BT::node* root, int data){
    // if value is found return
    if(root==NULL || root->data == data) return root;

    // traverse tree
    else if(root->data >= data) return search_node(root->left_child, data);
    else return search_node(root->right_child, data);
};

struct BT::node* BT::find_minimum(struct BT::node* root)
{
    if(root != NULL && root->left_child != NULL){
        return find_minimum(root->left_child);
    }
    return root;
};

void BT::inOrder(struct BT::node* root)
{
    if(root != NULL){
        inOrder(root->left_child);
        cout<< root->data << " ";
        inOrder(root->right_child);
    }
}


void BT::preOrder(struct BT::node* root)
{
    if (root != NULL){
        cout<< root->data<< " ";
        preOrder(root->left_child);
        preOrder(root->right_child);
    }
}

void BT::postOrder(struct BT::node* root)
{
    if (root != NULL){
        postOrder(root->left_child);
        postOrder(root->right_child);
        cout<< root->data<< " ";
    }
};

int main()
{
    BT obj;
    struct BT::node *root;
    root = obj.new_node(20);
    obj.insert_node(root, 5);
    obj.insert_node(root, 15);
    obj.insert_node(root, 9);
    obj.insert_node(root, 7);
    obj.insert_node(root, 30);
    obj.insert_node(root, 25);
    obj.insert_node(root, 40);
    obj.insert_node(root, 45);
    obj.insert_node(root, 42);
    obj.insert_node(root, 1);
    obj.insert_node(root, 12);

/* Original tree:
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
*/

    // print tree
    cout<< "BT (in-order): ";
    obj.inOrder(root);
    cout<< endl;

    // print tree
    cout<< "BT (pre-order): ";
    obj.preOrder(root);
    cout<< endl;

    // print tree
    cout<< "BT (post-order): ";
    obj.postOrder(root);
    cout<< endl;

    root = obj.delete_node(root, 5);

/*
After deleting node 5:
                   20
                 /    \
                /      \
               7       30
             /   \     /\
            /     \   /  \
           1      12 25   40
                /   \       \
               /     \       \
              9       15      45
                           /
                          /
                         42
*/
    cout<< "After deleting node 5 (in-order): ";
    obj.inOrder(root);
    cout<< endl;

    root = obj.delete_node(root, 40);

/* After deleting node 40:
                   20
                 /    \
                /      \
               7       30
             /   \     /\
            /     \   /  \
           1      12 25  42
                /   \      \
               /     \      \
              9       15     45
*/
    cout<< "After deleting node 40 (in-order): ";
    obj.inOrder(root);
    cout<< endl;
    return 0;
}
