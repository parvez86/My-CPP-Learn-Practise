class Solution {
    int getMaxDepth(TreeNode* root){
        if(!root) return 0;
        return max(getMaxDepth(root->left), getMaxDepth(root->right))+1;
    }
    void traverseInOrder(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        traverseInOrder(root->left, level+1, res);
        res[level].push_back(root->val);
        traverseInOrder(root->right, level+1, res);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = getMaxDepth(root);
        vector<vector<int>> res(n, vector<int>());
        traverseInOrder(root, 0, res);
        return res;
       }
}

