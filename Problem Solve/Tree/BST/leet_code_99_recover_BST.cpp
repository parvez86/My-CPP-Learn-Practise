
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
    TreeNode* addItem(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        else if(val < root->val) root->left = addItem(root->left, val);
        else root->right = addItem(root->right, val);

        return root;
    }

    bool check_BST(TreeNode* root, TreeNode* min_node, TreeNode* max_node){
        if(!root) return true;

        // check missing
        if(min_node && root->val < min_node->val){
            int temp = root->val;
            root->val = min_node->val;
            min_node->val = temp;
            return false;
        }
        else if(max_node && root->val > max_node->val){
            int temp = root->val;
            root->val = max_node->val;
            max_node->val = temp;
            return false;
        }
        return check_BST(root->left, min_node, root) && check_BST(root->right, root, max_node);;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        cout<< root->val<< " ";
        inOrder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        while(!check_BST(root, nullptr, nullptr));
    }

    TreeNode* insert_item(TreeNode* root, int val){
        return addItem(root, val);
    }

    void display(TreeNode* root){
        cout<< "The items are: ";
        inOrder(root);
        cout<< endl;
    }
};

int main()
{
    Solution obj;
    vector<int> vec{1,NULL,2,NULL,3,NULL,4,NULL,NULL};
    TreeNode* root = NULL;
    for(int i=0; i<vec.size(); i++){
        if(!vec[i]) continue;
        root = obj.insert_item(root, vec[i]);
    }
    obj.display(root);
    obj.recoverTree2(root);
    obj.display(root);
    return 0;
}
