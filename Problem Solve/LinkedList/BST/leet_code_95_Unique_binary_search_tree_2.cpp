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
    vector<TreeNode*> getUniqueBST(int left, int right){
        vector<TreeNode*> res;

        if(left > right) {res.push_back(NULL); return res;}

        if(left == right) {
            res.push_back(new TreeNode(left));
            return res;
        }

        for(int i=left; i<=right; i++){
            int mid = left+(right-left)*0.5;

            // make tree
            vector<TreeNode*> left_sub = getUniqueBST(left, mid-1);
            vector<TreeNode*> right_sub= getUniqueBST(mid+1, right);


            // get combinations
            for(auto l:left_sub){
                for(auto r:right_sub){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;

                    // store the combination
                    res.push_back(root);
                }
            }
        }
        return res;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return getUniqueBST(1, n);
    }
};


int main()
{
    Solution obj;
    int n=3;
    vector<TreeNode*> vec = obj.generateTrees(n);
    return 0;
}
