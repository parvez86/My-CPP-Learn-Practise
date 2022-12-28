class Solution {
    bool getPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum-=root->val;
        if(targetSum==0 && !root->left && !root->right) return true;
        return getPathSum(root->left, targetSum) || getPathSum(root->right, targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return getPathSum(root, targetSum);
    }
};

