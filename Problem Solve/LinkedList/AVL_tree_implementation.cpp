#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Right-Right Rotate
// rr rotation
TreeNode* rightToLeftRotate(TreeNode* root){
    TreeNode* new_root = root->right;
    TreeNode* r_node = new_root->left;

    // rotation
    new_root->left = root;
    root->right = r_node;

    return new_root;
}

// Left-Left Rotation
// ll rotation
TreeNode* leftToRightRotate(TreeNode* root){

    TreeNode* new_root = root->left;
    TreeNode* l_node = new_root->right;

    // rotation
    new_root->right = root;
    root->left = l_node;

    return new_root;
}

int getHeight(TreeNode* root){
    if(!root) return -1;
    int l_height = getHeight(root->left)+1;
    int r_height = getHeight(root->right)+1;

    return (l_height > r_height)? l_height : r_height;
}
int getHeight2(TreeNode* root){
    int h = 0;
    if(root){
        int l = getHeight(root->left)+1;
        int r = getHeight(root->right)+1;

        h = max(l, r)+1;
    }
    return h;
}

TreeNode* addItem(TreeNode* root, int val){

    // BST
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left  = addItem(root->left, val);
    else if(val > root->val) root->right = addItem(root->right, val);
    else return root;



    // Get balance
    int l_height = (!root || !root->left)? 0: getHeight(root->left);
    int r_height = (!root || !root->right)? 0: getHeight(root->right);

    int balance = l_height-r_height;

    // rr-rl rotation
    if (balance < -1){
        if(val < root->right->val) root->right = leftToRightRotate(root->right); // for rl rotation
        return rightToLeftRotate(root); // rr rotation
    }
    //  ll-lr rotation
    else if(balance > 1) {
        if(val > root->left->val) root->left = rightToLeftRotate(root->left); // for lr rotation
        return leftToRightRotate(root); // ll rotation
    }
    return root;
}

void inOrder(TreeNode* root){
    if(!root) return;
    inOrder(root->left);
    cout<< root->val<< " ";
    inOrder(root->right);
}

void preOrder(TreeNode* root){
    if(!root) return;
    cout<< root->val<< " ";
    preOrder(root->left);
    preOrder(root->right);
}

void display(TreeNode* root){
    cout<< "The nodes are: ";
    preOrder(root);
    cout<< endl;
}

void displayIn(TreeNode* root){
    cout<< "The nodes are: ";
    inOrder(root);
    cout<< endl;
}

int main()
{
    vector<int> vec{-10, -3, 0, 5, 9};
    TreeNode* root = NULL;
    for(int i=0; i < vec.size(); i++){
        root = addItem(root, vec[i]);
        displayIn(root);
    }
    return 0;
}
