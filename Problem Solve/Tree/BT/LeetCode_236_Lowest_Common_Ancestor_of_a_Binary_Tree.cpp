class Solution {
    TreeNode* travaresePostOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if (root->val==p->val || root->val == q->val) return root;
        TreeNode* l_child = travaresePostOrder(root->left, p, q);
        if(l_child && ((l_child->val == p->val && root->val==q->val)||  (l_child->val == q->val && root->val==p->val))) return root;
        TreeNode* r_child = travaresePostOrder(root->right, p, q);
        if(r_child && ((r_child->val == p->val && root->val==q->val)||  (r_child->val == q->val && root->val==p->val))) return root;

        return (l_child && r_child)? root: (l_child)?l_child:r_child;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return travaresePostOrder(root, p, q);
    }
};
