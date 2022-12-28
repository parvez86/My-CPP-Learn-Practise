class Solution {
    int searchNode(vector<int>& in, int inStart, int inEnd, int val){
        if(inStart>inEnd) return inEnd+1;
        if(in[inStart]==val) return inStart;
        return searchNode(in, inStart+1, inEnd, val);    }

    TreeNode* consturctBinaryTree(vector<int>& pre, int preStart, int preEnd, vector<int>&in, int inStart, int inEnd){
        if(inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        int rootIn = searchNode(in, inStart, inEnd, pre[preStart]);
        if(inStart != inEnd){
            int leftEndPre = preStart+rootIn-inStart;
            int rightStartPre = leftEndPre+1;
            root->left = consturctBinaryTree(pre, preStart+1, leftEndPre, in, inStart, rootIn-1);
            root->right = consturctBinaryTree(pre, rightStartPre, preEnd, in, rootIn+1, inEnd);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return consturctBinaryTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
