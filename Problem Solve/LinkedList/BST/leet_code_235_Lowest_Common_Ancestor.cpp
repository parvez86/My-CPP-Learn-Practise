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

class Solution {
    TreeNode* addNode(TreeNode* root, int data){
        if(!root) return new TreeNode(data);
        if(data <= root->val) root->left = addNode(root->left, data);
        else root->right = addNode(root->right, data);

        return root;
    }

    bool find_node(TreeNode* root, int p){
        if(!root) return false;
        if(root->val == p) return true;
        return (p <= root->val)? find_node(root->left, p):find_node(root->right, p);
    }

    TreeNode* inOrder(TreeNode* root, TreeNode* l, TreeNode* r){
        if(!root) return NULL;
        if(root==l && find_node(root->right, r->val)) return root;
        else if(root == r && find_node(root->left, l->val)) return root;
        else if(find_node(root->left, l->val) && find_node(root->right, r->val)) return root;
        return (r->val < root->val)? inOrder(root->left, l, r):inOrder(root->right, l, r);
    }

    TreeNode* inOrder2(TreeNode* root, TreeNode* l, TreeNode* r){
        if(!root) return NULL;
        if(root->left && root==r && root->left==l) return root;
        else if(root->right &&  root==l && root->right==r) return root;
        else if(root->left==l && root->right==r) return root;
        return (r->val < root->val)? inOrder(root->left, l, r):inOrder(root->right, l, r);
    }

    void display(TreeNode* root){
        if(!root) return;
        display(root->left);
        cout<< root->val<< " ";
        display(root->right);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return (p->val <= q->val)? inOrder(root, p, q):inOrder(root, q, p);
    }
     TreeNode* add(TreeNode* root, int val){
         return addNode(root, val);
     }
     void printTree(TreeNode* root){
         cout<< "The nodes are: ";
         display(root);
         cout<< endl;
     }
};

int main()
{
    Solution obj;
    int arr[] = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root=NULL;
    for(int i=0; i<len; i++){
        if(arr[i]) root = obj.add(root, arr[i]);
    }
    obj.printTree(root);
    TreeNode* lca = obj.lowestCommonAncestor(root, root->left->right, root->left);
    (lca)?cout<< lca->val<< endl:cout<< "NULL"<< endl;
    return 0;
}
