#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* root = new TreeNode;
    TreeNode* addNode(TreeNode* head, int val){
        if(!head){
            head = new TreeNode(val);
        }else{
            if(head->val >= val) head->left = addNode(head->left, val);
            else head->right = addNode(head->right, val);
        }

        return head;
    }

    void inorder(TreeNode* curr){

        if(!curr) return;
        inorder(curr->left);
        root = addNode(root, curr->val);
        inorder(curr->right);
    }

    void getPreOrder(TreeNode* root, vector<int>& vec){

        if(!root) return;
        getPreOrder(root->left, vec);
        vec.push_back(root->val);
        getPreOrder(root->right, vec);
    }

    void display_in_pre_order(TreeNode* root){
        if(!root) {cout<< endl; return;}
        display_in_pre_order(root->left);
        cout<< root->val<< " ";
        display_in_pre_order(root->right);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder(root2);

        vector<int> vec;
        getPreOrder(root, vec);

        if(vec[0]==0) vec.erase(vec.begin());
        else {
            auto it = find(vec.begin(), vec.end(), 0);
            vec.erase(it);
        }
        return vec;
    }
    vector<int> getAllElements2(TreeNode* root1, TreeNode* root2) {
        vector<int> vec;
        getPreOrder(root1, vec);
        getPreOrder(root2, vec);
        sort(vec.begin(), vec.end());
        return vec;
    }
    TreeNode* makeTree(TreeNode* head, int val){
        return addNode(head, val);
    }
    void displayTree(TreeNode* head){
        cout<< "The elements of tree: ";
        display_in_pre_order(head);
    }
};


int main()
{
    Solution obj;
    TreeNode* root1;
    TreeNode* root2;
    int head1[] = {0,-10,10};
    int len1 = sizeof(head1)/sizeof(head1[0]);
    if(len1>0){
        root1 = new TreeNode(head1[0]);
        for(int i=1; i<len1; i++){

            root1 = obj.makeTree(root1, head1[i]);
        }
        // obj.displayTree(root1);
    }

    int head2[] = {5,1,7,0,2};
    int len2 = sizeof(head2)/sizeof(head2[0]);
    if(len2>0){
        root2 = new TreeNode(head2[0]);
        for(int i=1; i<len2; i++){
            root2 = obj.makeTree(root2, head2[i]);
        }
        // obj.displayTree(root2);
    }

    vector<int> res = obj.getAllElements2(root1, root2);
    for(auto it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}



/*
Test cases
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10

root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
*/


