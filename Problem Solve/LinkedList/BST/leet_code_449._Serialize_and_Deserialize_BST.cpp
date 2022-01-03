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

class Codec {
    TreeNode* addNodeToDeserializer(TreeNode* root, int key){
        if(!root) return new TreeNode(key);
        if(key < root->val) root->left = addNodeToDeserializer(root->left, key);
        else root->right = addNodeToDeserializer(root->right, key);
        return root;
    }

    void preOrderSerializer(TreeNode* root, string& ser){
        if(!root) return;
        ser+=to_string(root->val)+" ";
        preOrderSerializer(root->left, ser);
        preOrderSerializer(root->right, ser);
    }

    void preOrder(TreeNode* root){
        if(!root) return;
        cout<< root->val<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }

public:

    TreeNode* add(TreeNode* root, int key){
        return addNodeToDeserializer(root, key);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser="";
        preOrderSerializer(root,ser);
        cout<< "The serialize output: "<< ser<< endl;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        TreeNode* root = NULL;
        int num;
        int prev_indx = 0;
        stringstream ss(data);
        while(ss >> num){
            root = addNodeToDeserializer(root, num);
        }
        return root;
    }

    void dispPre(TreeNode* root){
        cout<< "The tree in pre-order: "<< endl;
        preOrder(root);
        cout<< endl;
    }

};

int main()
{
    vector<int>nums{41,37,44,24,39,42,48,1,35,38,40,NULL,43,46,49,0,2,30,36,
    NULL,NULL,NULL,NULL,NULL,NULL,45,47,NULL,NULL,NULL,NULL,NULL,4,29,32,NULL,
    NULL,NULL,NULL,NULL,NULL,3,9,26,NULL,31,34,NULL,NULL,7,11,25,27,NULL,NULL,
    33,NULL,6,8,10,16,NULL,NULL,NULL,28,NULL,NULL,5,NULL,NULL,NULL,NULL,NULL,
    15,19,NULL,NULL,NULL,NULL,12,NULL,18,20,NULL,13,17,NULL,NULL,22,NULL,14,NULL,NULL,21,23};

    TreeNode* root = NULL;
    Codec obj;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]) root = obj.add(root, nums[i]);
    }

    TreeNode* new_root = obj.deserialize(obj.serialize(root));
    obj.dispPre(new_root);
    return 0;
}
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
