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


class Solution{
    TreeNode* addNode(TreeNode* root, int key){
        if(!root) return new TreeNode(key);
        if(key <= root->val) root->left = addNode(root->left, key);
        else root->right = addNode(root->right, key);

        return root;
    }

    TreeNode* delete_node(TreeNode* root, int key){
       // if(!root || (!root->left && !root->right && root->val==key)) return NULL;
        if(!root) return NULL;
        if(key < root->val) root->left = delete_node(root->left, key);
        else if (key > root->val) root->right= delete_node(root->right, key);
        else if(root->left && root->right) {
            TreeNode* temp = get_minimum(root->right);
            root->val = temp->val;
            if(root) root->right = delete_node(root->right, root->val);
        }
        else{
            TreeNode* temp = root;
            if(root->left) root = root->left;
            if(root->right) root = root->right;
            delete temp;
        }

        return root;
    }

    TreeNode* get_minimum(TreeNode* root){
        if(!root || !root->left ) return root;
        root = get_minimum(root->left);
        return root;
    }

    void display_in_pre_order(TreeNode* root){
        if(!root) {return;}
        cout<< root->val<< " ";
        display_in_pre_order(root->left);
        display_in_pre_order(root->right);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        displayNode2(root);
        return delete_node(root, key);
    }

    TreeNode* insertNode(TreeNode* root, int key){
        return addNode(root, key);
    }

    void displayNode(TreeNode* root){
        if(!root) return;
        cout<< root->val;
        if(root->left || root->right) cout<< ",";
        displayNode(root->left);
        displayNode(root->right);
    }

    void displayNode2(TreeNode* root){
        cout<< "The nodes are: ";
        display_in_pre_order(root);
        cout<< endl;
    }
};

int main()
{
    Solution obj;
    int arr[] = {44,11,45,7,21,NULL,49,6,8,13,24,47,NULL,0,NULL,NULL,
    9,12,19,23,25,46,48,NULL,2,NULL,10,NULL,NULL,15,20,22,NULL,NULL,
    38,NULL,NULL,NULL,NULL,1,3,NULL,NULL,14,16,NULL,NULL,NULL,NULL,
    33,41,NULL,NULL,NULL,5,NULL,NULL,NULL,18,29,34,40,43,4,NULL,17,
    NULL,27,30,NULL,36,39,NULL,42,26,28,31,35,37,32};
   // int arr[] = {60,30,70,NULL,40,NULL,80};

    int len = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = NULL;
    for(int i=0; i<len; i++){
        if(arr[i]) root = obj.insertNode(root, arr[i]);
    }
    int key = 49;
   // int key = 50;
    root = obj.deleteNode(root, key);
  //  cout<< "[";
    obj.displayNode2(root);
    // cout<< "]"<< endl;
    return 0;
}
