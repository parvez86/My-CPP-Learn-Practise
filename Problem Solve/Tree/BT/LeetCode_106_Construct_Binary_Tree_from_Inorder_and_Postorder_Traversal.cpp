#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r):val(0), left(l), right(r){}
};

class Solution {
    int searchNode(vector<int>& inorder, int start, int end, int val){
        if(start>=end) end+1;
        if(inorder[start]==val) return start;
        return searchNode(inorder, start+1, end, val);
    }

    TreeNode* constructBinaryTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder,
                                 int posStart, int posEnd){
        if(inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[posEnd]);

        if(inStart != inEnd){
            // find root
            int rootIn = searchNode(inorder, inStart, inEnd, postorder[posEnd]);

            // re-calculate left & right branch
            int leftEndIn = rootIn-1;
            int rightStartIn = rootIn+1;

            int leftEndPos = posStart+leftEndIn-inStart;
            int rightStartPos = leftEndPos+1;

            root->left = constructBinaryTree(inorder, inStart, leftEndIn, postorder, posStart, leftEndPos);
            root->right = constructBinaryTree(inorder, rightStartIn, inEnd, postorder, rightStartPos, posEnd -1);
        }

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return constructBinaryTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    void displayIn(TreeNode* root){
        if(!root) return;
        displayIn(root->left);
        cout<< root->val<< " ";
        displayIn(root->right);
    }
    void displayPre(TreeNode* root){
        if(!root) return;
        cout<< root->val<< " ";
        displayPre(root->left);
        displayPre(root->right);
    }
};


int main()
{
    Solution obj;
    // vector<int> inorder = {9,3,15,20,7};
    vector<int> inorder = {1,2,3,4};
    // vector<int> postorder = {9,15,7,20,3};
    vector<int> postorder = {2,1,4,3};

    TreeNode* root = obj.buildTree(inorder, postorder);
    cout<< "The tree are: "<< endl;
    obj.displayPre(root);
    cout<< endl;
    cout<< "The tree are(in-order): "<< endl;
    obj.displayIn(root);
    return 0;
}
