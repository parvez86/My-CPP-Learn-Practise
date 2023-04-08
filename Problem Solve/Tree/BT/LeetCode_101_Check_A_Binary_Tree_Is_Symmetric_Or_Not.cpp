/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define branch pair<TreeNode*, TreeNode*>
class Solution {
    bool checkSymmetricPrNotItertive(TreeNode* root){
        queue<branch> q;
        q.push(make_pair(root->left, root->right));
        while(!q.empty()){
            branch temp = q.front();
            q.pop();
            if(!temp.first && !temp.second) continue;
            if(!temp.first || !temp.second || temp.first->val != temp.second->val) return false;
            q.push(make_pair(temp.first->left, temp.second->right));
            q.push(make_pair(temp.first->right, temp.second->left));
        }
        return true;
    }

    void checkSymmetricPrNotRecursive(TreeNode* left, TreeNode* right, bool& isSym){
        if(!left && !right) return;
        if(!left || !right || left->val != right->val){
            isSym = false;
            return;
        }
        checkSymmetricPrNotRecursive(left->left, right->right, isSym);
        checkSymmetricPrNotRecursive(left->right, right->left, isSym);
    }

    bool checkSymmetricPrNotRecursive2(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right || left->val != right->val){
            return false;
        }
        return checkSymmetricPrNotRecursive2(left->left, right->right) &&
        checkSymmetricPrNotRecursive2(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        // for iterative approach
        // return checkSymmetricPrNotItertive(root);

        // for recursive approach
        // approach 1:
        // bool isSym = true;
        // checkSymmetricPrNotRecursive(root->left, root->right, isSym);
        // return isSym;

        // approach: 2
        return checkSymmetricPrNotRecursive2(root->left, root->right);
    }
};

