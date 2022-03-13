#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    vector<vector<int>> res_arr;
    vector<int> level;

    void bfs(Node* start){
        res_arr.push_back({start->val});
        queue<Node*> q;
        q.push(start);
        level.push_back(0);

        cout<< "hi"<< endl;
        while(!q.empty()){
            Node* root = q.front();
            q.pop();
            if(!root || root->children.size()==0) continue;
            if(!root) continue;
            for(Node* node:root->children){
                if(!node) continue;
                while(res_arr.size()<=node->val) {res_arr.push_back({});level.push_back(0);}
                level[node->val] = level[root->val]+1;
                res_arr[level[root->val]].push_back(node->val);
                q.push(node);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return {};
        if(root) res.push_back({root->val});
        traverse(root, 1, res);
        res.pop_back();
        return res;
    }
    vector<vector<int>> levelOrder2(Node* root) {

        // incomplete
        if(!root) return {};
        bfs(root);
        return res_arr;
    }
    void traverse(Node* root, int level, vector<vector<int>>& res){
        if(!root) return;
        if(res.size()<=level) res.push_back({});
        for(Node* node:root->children) if(node) res[level].push_back(node->val);
        for(Node* node:root->children) traverse(node, level+1, res);
    }
};

int main()
{
    Solution obj;
    queue<Node*> q;
    vector<int> nodes = {1,NULL,2,3,4,5,NULL,NULL,6,7,NULL,8,NULL,9,10,NULL,NULL,11,NULL,12,NULL,13,NULL,NULL,14};
    Node* root = NULL;
    if(nodes.size()>0) root = new Node(nodes[0]);
    q.push(root);
    vector<Node*> temp_nodes;
    for(int i=2; i<nodes.size(); i++){
        if(!nodes[i]) {
            q.front()->children = temp_nodes;
            temp_nodes.clear();
            if(!q.empty()) q.pop();
        }
        Node* node = new Node(nodes[i]);
        temp_nodes.push_back(node);
        q.push(node);
    }
    vector<vector<int>> res = obj.levelOrder(root);
    for(auto it:res){
        if(it.size()==0) continue;
        cout<< "[";
        for(int n:it) cout<< n<< " ";
        cout<< "]";
    }

    vector<vector<int>> res2 = obj.levelOrder2(root);
    for(auto it:res2){
        if(it.size()==0) continue;
        cout<< "[";
        for(int n:it) cout<< n<< " ";
        cout<< "]";
    }
    return 0;
}
