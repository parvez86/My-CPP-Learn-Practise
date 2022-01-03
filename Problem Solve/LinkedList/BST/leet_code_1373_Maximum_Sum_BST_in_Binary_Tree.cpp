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
    int max_sum = 0;
    const int min_val = -40001;
    const int max_val = 40001;

    TreeNode* insert_item(TreeNode* root, int val){
        if(!root) return new TreeNode(val);

        if (val <= root->val) root->left = insert_item(root->left, val);
        else if (val > root->val) root->right = insert_item(root->right, val);

        return root;
    }

    vector<int> get_SUM(TreeNode* root){
        // resultant vec: {left_max, right_min, sum, isBST}
        if(!root) return vector<int>{min_val, max_val, 0, 1};

        vector<int> l_sub = get_SUM(root->left);
        vector<int> r_sub = get_SUM(root->right);

        // get max value of left subtree & current node
        int l_max = max({root->val, l_sub[0], r_sub[0]});
        // get min value of right subtree & current node
        int r_min = min({root->val, l_sub[1], r_sub[1]});
        // get sum of bst
        int sum = l_sub[2] + r_sub[2] + root->val;

        vector<int>vec {l_max, r_min, sum, 0};

        // if left subtree & right subtree is BST & left_max < root->val < right_min
        // update max sum
        // set current root is BST
        if(l_sub[3]==1 && r_sub[3]==1 && root->val > l_sub[0] && root->val < r_sub[1]){
            vec[3] = 1;
            max_sum= max(max_sum, vec[2]);
        }
        // cout<< root->val << " "<< vec[0]<< " "<< vec[1]<< " "<< vec[2]<< " "<< vec[3]<< " "<< endl;
        return vec;
    }

    vector<int> get_SUM2(TreeNode* root){
        // resultant vec: {min_val, max_val, sum, isBST}

        if(!root) return vector<int>{40001, -40001, 0, 1};

        // if the node is leaf node
        // update sum & return value
        if(!root->left && !root->right) {
            max_sum = max(max_sum, root->val);
            return {root->val, root->val, root->val, 1};
        }

        vector<int> l_sub = get_SUM2(root->left);   // for left subtree
        vector<int> r_sub = get_SUM2(root->right);  // for right subtree

        // get min value of current root & left subtree
        int min_val = min(root->val, l_sub[0]);
        // get max value of current root & right subtree
        int max_val = max(root->val, r_sub[1]);
        // get sum of current root
        int sum = l_sub[2] + r_sub[2] + root->val;

        vector<int>vec {min_val, max_val, sum, 0};

        // if both left & right subtree is BST & left_Max < root->val << right_min
        // set current root is BST
        // update max sum
        if(l_sub[3]==1 && r_sub[3]==1 && root->val > l_sub[1] && root->val < r_sub[0]){
            vec[3] = 1;
            max_sum= max(max_sum, vec[2]);
        }
        // cout<< root->val << " "<< vec[0]<< " "<< vec[1]<< " "<< vec[2]<< " "<< vec[3]<< " "<< endl;
        return vec;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        cout<< root->val<< " ";
        inOrder(root->right);
    }

public:
    int maxSumBST(TreeNode* root) {
    //    vector<int> vec{INT_MIN, INT_MAX, 0, 0, 0};
        int sum = get_SUM2(root)[2];
        cout<< max_sum<< endl;
        return sum;
    }

    TreeNode* addItem(TreeNode* root, int val){
        return insert_item(root, val);
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
    vector<int> vec{1,4,3,2,4,2,5,NULL,NULL,NULL,NULL,NULL,NULL,4,6};
    TreeNode* root = NULL;
    for(int i=0; i< vec.size(); i++) {
        if(!vec[i]) continue;
        root = obj.addItem(root, vec[i]);
    }
    obj.display(root);
    cout<< obj.maxSumBST(root)<< endl;
    return 0;
}
