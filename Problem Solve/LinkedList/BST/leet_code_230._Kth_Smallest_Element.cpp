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

    void get_kth(TreeNode* root, int& k){
        if(!root) return ;
        get_kth(root->left, k);
        if(k==1) {k==root->val;return;}
        k-=1;
        get_kth(root->right, k);
    }

    void display(TreeNode* root){
        if(!root) return;
        display(root->left);
        cout<< root->val<< " ";
        display(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        get_kth(root, k);
        return vec[k-1];
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
    int arr[] = {3,1,4,NULL,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root=NULL;
    for(int i=0; i<len; i++){
        if(arr[i]) root = obj.add(root, arr[i]);
    }
    int k=1;
    obj.printTree(root);
    int val= obj.kthSmallest(root, k);
    cout<< val<< endl;;
    return 0;
}

