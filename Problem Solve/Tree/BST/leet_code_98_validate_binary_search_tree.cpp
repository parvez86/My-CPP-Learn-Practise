#include <iostream>
#include <vector>
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
    bool isValid = true;
    void inOrder(TreeNode* root, int mx, int mn){
        if(!root) return;
        inOrder(root->left, root->val, mn);
        if(root->val < mn || root->val > mx) {isValid = false; return;}
        inOrder(root->right, root->val, mx);
    }

    TreeNode* addNode(TreeNode* root, int key){
        if(!root) return new TreeNode(key);
        if(key <= root->val) root->left = addNode(root->left, key);
        else root->right = addNode(root->right, key);

        return root;
    }
public:
    bool isValidBST(TreeNode* root) {
        inOrder(root, INT_MAX, INT_MIN);
        return isValid;
    }

    TreeNode* add(TreeNode* root, int key){
        return addNode(root, key);
    }
};

int main()
{
    Solution obj;
    vector<int> nums{3,1, 4, NULL, 2};
    TreeNode* root = NULL;
    int len = nums.size();
    for(int i=0; i<len; i++) {if(nums[i]) root = obj.add(root, nums[i]);}
    cout<< obj.isValidBST(root)<< endl;
    return 0;
}
